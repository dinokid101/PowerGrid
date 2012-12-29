package powerwalk.model.world;

import powerwalk.model.OutOfReachException;

/**
 * This class represents a mobile, non-aggressive object in the RSBot environment that can be interacted with.
 * @author Chronio
 */
public class Person extends Entity {

    /**
     *
     */
    public static final int[] pValues = new int[] {};
    
    /**
     * Creates a new Person at the given position. the <code>rawValue</code> 
     * indicates the type of object as provided by the RSBot environment.
     * @param x the x-coordinate of this object
     * @param y the y-coordinate of this object
     * @param z the z-coordinate of this object
     * @param rawValue the raw value from the environment specifying the type
     */
    public Person(int x,int y, int z, int rawValue) {
        super(x,y,z,rawValue);
    }
    
    /**
     * Interacts with this Person using the default method.
     * <p>For most Characters, the default interaction method is "talk to" or "speak to".</p>
     * @throws OutOfReachException when the interaction could not be completed
     */
    @Override public void interact() throws OutOfReachException {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    /**
     * Interacts with this Person using the given method
     * @param method the method of interaction
     * @throws OutOfReachException when the interaction could not be completed
     */
    @Override public void interact(String method) throws OutOfReachException {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
