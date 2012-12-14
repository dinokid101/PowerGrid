package powerwalk.control;

import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Utility class providing shortcuts to standard commonly used tasks
 * @author P.Kramer
 */
public abstract class ToolBox {
    
    /**
     * returns the first index i was found in arr, or -1 if arr does not contain i
     * @param i the element to look for
     * @param arr the array to search in
     * @return the index of i in arr
     */
    public static int arrayIndexOf(int i, int[] arr) {
        for (int k=0;k<arr.length;k++) {
            if (arr[k] == i) return k;
        }
        return -1;
    }
    
    /**
     * returns the first index i was found in arr, or -1 if arr does not contain i.
     * <p>This method is faster than arrayIndexOf(), but requires the elements of 
     * the array to be sorted in ascending order.</p>
     * 
     * <p>Note that his method does not guarantee to give the index of the first 
     * matching element. The index of any matching element may be returned.</p>
     * 
     * <p>Please be aware that this method may not give the right answer when 
     * the array is not sorted. Only calls to this method with sorted arrays are 
     * guaranteed to return the right answer.</p>
     * @param i the element to look for
     * @param arr the array to search in
     * @return the index of i in arr
     */
    public static int sortedArrayIndexOf(int i,int[] arr) {
        int start=0, end=arr.length-1;
        int mid = (start+end) /2;
        
        while (start < end) {
            if (arr[mid] == i) return mid;
            if (arr[mid] < i) {
                start = mid;
                mid = (start+end)/2;
            } else {
                end = mid;
                mid = (start+end)/2;
            }
        }
        if (arr[start] == i) return start;
        else return -1;
    }
    
    /**
     * Returns a HashMap containing the attributes and their values from a valid XML-String
     * @param xml The XML-String to parse
     * @return a HashMap containing the attributes and values parsed from xml
     */
    public static HashMap<String,String> getAttributes(String xml) {
        HashMap<String,String> vals = new HashMap<>();
        xml = xml.substring(xml.indexOf(" ",xml.indexOf("<")),xml.lastIndexOf(">"));
        while (!xml.isEmpty()) {
            try {
                xml = xml.trim();
                int is = xml.indexOf("=",0);
                int openVal = xml.indexOf("'",is);
                int closeVal  = xml.indexOf("'",openVal+1);
                if (openVal == -1 || closeVal == -1) {
                    openVal = xml.indexOf("\"",is);
                    closeVal = xml.indexOf("\"",openVal+1);
                }
                String att = xml.substring(0, is);
                String val = xml.substring(openVal+1,closeVal);
                vals.put(att, val);
                xml = xml.substring(closeVal+1);
            } catch (StringIndexOutOfBoundsException e) {
                Logger.getLogger("control").log(Level.FINE,"While decoding XML-data, the following could not be parsed:\n"
                                                            + "\"{0}\"\n"
                                                            + "The following data could be parsed:\n"
                                                            + "{1}",new Object[] {xml,vals});
                break;
            }
        }
        return vals;
    }
    
    /**
     * Parses and returns the tag name from the given XML-String
     * @param xml the XML-String to parse the tag name for
     * @return the tag name of the XML-String
     */
    public static String getTagFromXML(String xml) {
        int index = xml.indexOf("<");
        int start = index+1;
        int end = xml.indexOf(" ",start);
        if (end == -1) end = xml.indexOf(">");
        else end = Math.min( end, xml.indexOf(">"));
        String res = xml.substring(start,end);
        if (res.startsWith("/")) res = res.substring(1,res.length());
        return res;
    }
}
