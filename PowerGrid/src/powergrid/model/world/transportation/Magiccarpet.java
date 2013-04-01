/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.model.world.transportation;

import org.powerbot.game.client.RSGround;
import powergrid.model.Point;
import powergrid.model.TransportTile;
import powergrid.model.network.GraphNetwork;
import powergrid.model.network.TransportNetwork;

/**
 *
 * @author Vincent W
 */
public class Magiccarpet extends TransportTile {
    
    private String name;
    
    public Magiccarpet(Point pos, RSGround ground, int colFlag) {
        super(pos, ground, colFlag);
    }
    
    @Override 
    public GraphNetwork getNetwork(){
        return (GraphNetwork) super.getNetwork();
    }
    
    @Override
    public Magiccarpet withNetwork(TransportNetwork nw) {
        if(nw instanceof GraphNetwork){
        super.withNetwork(nw);
        return this;
        } else { 
            return null;
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    
}
