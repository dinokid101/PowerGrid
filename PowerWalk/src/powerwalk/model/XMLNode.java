package powerwalk.model;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;

/**
 * An XML node in an XML tree.
 * @author P.Kramer
 */
public class XMLNode {
    private String tag;
    private HashMap<String,String> attributes;
    private ArrayList<XMLNode> children;

    public XMLNode(String tag, HashMap<String, String> attributes, ArrayList<XMLNode> childs) {
        this.tag = tag;
        this.attributes = attributes;
        this.children = childs;
    }

    /**
     * returns the tag of this XMLNode
     * @return the tag of this XMLNode
     */
    public String getTag() {
        return tag;
    }
    
    /**
     * returns a List of all XMLNodes that are direct children of this XMLNode 
     * and have the specified tag.
     * @param childTag the tag to look for
     * @return the List of all direct children of this XMLNode that have the desired tag
     */
    public ArrayList<XMLNode> getAll(String childTag) {
        if (children == null) return new ArrayList<>(1);
        ArrayList<XMLNode> res = new ArrayList<>(Math.max(10, children.size()));
        for (XMLNode n : children) {
            if (n.getTag().equals(childTag))
                res.add(n);
        }
        return res;
    }
    
    /**
     * returns whether this tag auto-closes or not. Auto-closing tags cannot have children
     * @return true if this XMLNode auto-closes, false otherwise
     */
    public boolean isSelfClosing() {
        return children == null;
    }
    
    /**
     * returns a List of all direct and indirect children of this XMLNode that have 
     * @param childTag the tag to look for
     * @return a List of XMLNodes with the desired tag
     */
    public ArrayList<XMLNode> getAllRecursive(String childTag) {
        if (isSelfClosing()) return new ArrayList<>(1);
        ArrayList<XMLNode> res = getAll(childTag);
        for (XMLNode n : children) {
            res.addAll(n.getAllRecursive(childTag));
        }
        return res;
    }

    /**
     * returns a Map containing all the XMLNode's attributes and the respective values.
     * @return a Map containing the attributes and values
     */
    public HashMap<String, String> getAttributes() {
        return attributes;
    }

    /**
     * returns a list of the children of this XML Node.
     * @return a list of the children of this XML Node
     */
    public ArrayList<XMLNode> children() {
        if (isSelfClosing()) 
            return new ArrayList<>(1);
        else 
            return new ArrayList<>(children);
    }
    
    /**
     * returns the value for the given attribute.
     * @param att the attribute to look up
     * @return the value for the attribute, or null if no such value exists
     */
    public String get(String att) {
        return attributes.get(att);
    }
    
    /**
     * returns the XML for the XML tree with this Node as its root
     * @return a String-representation of this XML tree
     */
    @Override public String toString() {
        return "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + toString("");
    }
    
    /**
     * helper method for toString() to build the XML String recursively.
     * @param prefix the prefix for each line of XML
     * @return the XML-tree for this XMLNode, where each line is prefixed with 
     *         the specified prefix
     */
    private String toString(String prefix) {
        
        String res = prefix + "<" + tag + (attributes.isEmpty() ? "" : " ");
        for (Entry<String,String> att : attributes.entrySet()) {
            res += att.getKey() + "=\"" + att.getValue() + "\" ";
        }
        if (isSelfClosing()) {
            if (tag.startsWith("?")) {
                res += "?>";
            } else {
                res += "/>\n";
            }
        } else {
            res += ">\n";
            for (XMLNode n : children) {
                res += prefix + n.toString(prefix + "  ");
            }
            res += prefix + "</" + tag + ">\n";
        }
        return res;
    }
}
