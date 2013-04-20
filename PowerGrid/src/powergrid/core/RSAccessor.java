package powergrid.core;

import java.applet.Applet;
import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.regex.Matcher;
import static powergrid.PowerGrid.LOGGER;

/**
 * Loads the RS client and provides access methods to interact with the client.
 *
 * @author Chronio
 */
public class RSAccessor {

    private URL base;
    private Applet rsClient = null;
    private byte[] loader = null;

    /**
     * Creates a new RSAccessor instance.
     *
     * @param base The base URL to load from
     */
    public RSAccessor(URL base) {
        assert base != null;
        this.base = base;
    }

    /**
     * Returns the running RS Applet.
     *
     * @return the Runescape Applet
     */
    public Applet getRSClient() {
        return rsClient;
    }

    /**
     * Returns whether the client has been loaded.
     *
     * @return true if the client has been loaded, false otherwise.
     */
    public boolean isLoaded() {
        return rsClient != null;
    }

    /**
     * Returns the URL used as the base for loading the client.
     *
     * @return the base URL
     */
    public URL getBaseURL() {
        return base;
    }

    /**
     * Navigates the Runescape site to fetch the loader, then downloads and runs
     * it.
     *
     * @return true if and only if the operation was successful, false
     * otherwise.
     */
    public boolean load() {
        HTTPClient client = new HTTPClient(getBaseURL());
        try {
            client.follow(new URL(getBaseURL().toString() + "game.ws?j=1"));
            // find the source of the frame's contents
            URL url = client.findAndFollow("src=\"(.*)\" frameborder");
            // find the java archive this source links to
            String archiveLink = client.findFirst("archive=(.*) ", 1);
            url = new URL(url.getProtocol() + "://"
                    + url.getHost() + "/" + archiveLink);
            String className = client.findFirst("code=(.*) ", 1);
            HashMap<String, String> params = new HashMap<>(16, 7 / 8f);
            Matcher m = client.find("<param name=\"([^\\s]+)\"\\s+value=\"([^>]*)\">");
            while (m.find()) {
                params.put(m.group(1), m.group(2));
            }
            if (params.containsKey("haveie6")) {
                params.put("haveie6", "false");
            }
            return setupLoader(client, url, className, params);
        } catch (IOException e) {
            LOGGER.log(Level.SEVERE,
                    "An Exception occurred while loading RS client", e);
        } catch (IllegalStateException e) {
            LOGGER.log(Level.SEVERE,
                    "Required data not found in URL: " + client.getCurrent(), e);
        }
        return false;
    }

    /**
     * Downloads the Runescape Loader from the given URL, then instantiates it
     * using the given className and parameters.
     *
     * @param client the HTTPClient to use
     * @param url the URL to load from
     * @param className the name of the class to run
     * @param params the Applet parameters
     * @return
     */
    private boolean setupLoader(HTTPClient client, URL url, String className,
            Map<String, String> params) throws IOException {
        client.follow(url);
        loader = client.getContentsAsBytes("cache" + File.separator + "loader.cache");
        String secretKey = params.get("0");
        String ivParamKey = params.get("-1");
        if (secretKey == null || ivParamKey == null) {
            LOGGER.severe("invalid security keys: aborting");
            return false;
        }

        return false;
    }

    /**
     * Unscrambles the given key and returns it in a byte array.
     * @param key the key to unscramble
     * @return a byte array containing the unscrambled key
     */
    private byte[] unscrambleKeyJava(String key) {
        int keyLength = key.length();
        if (keyLength == 0) {
            return new byte[0];
        }
        int lengthMod = -4 & keyLength + 3;
        int unscrambledLength = lengthMod / 4 * 3;
        if (keyLength <= lengthMod - 2 || charIndex(key.charAt(lengthMod - 2)) == -1) {
            unscrambledLength -= 2;
        } else if (keyLength <= lengthMod - 1 || -1 == charIndex(key.charAt(lengthMod - 1))) {
            --unscrambledLength;
        }

        byte[] bytes = new byte[unscrambledLength];
        int offset = 0;
        int pos = 0;

        while (pos < keyLength) {
            int pos_1 = keyLength > pos + 1 ? charIndex(key.charAt(pos + 1)) : -1;
            bytes[offset++] = (byte) (pos_1 >>> 4 | charIndex(key.charAt(pos)) << 2);
            if (pos + 2 < keyLength) {
                int pos_2 = charIndex(key.charAt(2 + pos));
                if (pos_2 >= 0) {
                    bytes[offset++] = (byte) (pos_1 << 4 & 240 | pos_2 >>> 2);
                    if (pos + 3 < keyLength) {
                        int pos_3 = charIndex(key.charAt(3 + pos));
                        if (pos_3 >= 0) {
                            bytes[offset++] = (byte) (192 & pos_2 << 6 | pos_3);
                            pos += 4;
                            continue;
                        }
                    }
                }
            }
            break;
        }
        return bytes;

    }

    private native byte[] unscramble(String key, int offset);
    
    /**
     * Looks up the char index of the provided char. 
     * @param c the char to look up
     * @return the index belonging to that char
     */
    private int charIndex(char c) {
        if (c >= 42 && c < 122) {
            if (c >= 65 && c <= 90) {
                return c - 65;
            }
            if (c >= 97 && c <= 122) {
                return c + 26 - 97;
            }
            if (c >= 48 && c <= 57) {
                return c + 4;
            }
            if (c == 42 || c == 43) {
                return 62;
            }
            if (c == 45 || c == 47) {
                return 63;
            }
        }
        return -1;
    }
}