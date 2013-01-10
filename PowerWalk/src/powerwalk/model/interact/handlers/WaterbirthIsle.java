package powerwalk.model.interact.handlers;

import java.util.ArrayList;
import powerwalk.model.Point;
import powerwalk.model.interact.Transportable;

/**
 *
 * @author Alaineman
 */
public class WaterbirthIsle extends Transportable{

    // id _2435 , pos (2621,3683) "Travel-Waterbirth"
    // id _2438 , pos (2544,3761) "Travel-Rellekka"
    
    public WaterbirthIsle(Point p){
        super(p.x, p.y, p.z, -1, new ArrayList<WaterbirthIsle>(1));
    }
    
    @Override
    protected void handle(Transportable dest) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    protected void waitForCompletion(Transportable dest) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
