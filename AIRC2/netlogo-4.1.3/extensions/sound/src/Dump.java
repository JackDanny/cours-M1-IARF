/** (c) 2004 Uri Wilensky. See README.txt for terms of use. **/

package edu.nwu.ccl.nlogo.extensions.sound ;

/**
 * Returns debug information about the state of the synthesizer.
 **/
public class Dump
    implements org.nlogo.api.Reporter
{
    public String getAgentClassString()
    {
        return "OTP" ;
    }

    public org.nlogo.api.Syntax getSyntax()
    {
        return org.nlogo.api.Syntax.reporterSyntax( 
            org.nlogo.api.Syntax.TYPE_STRING 
        );
    }

    public boolean getSwitchesBoolean() { return false; }

    public org.nlogo.api.Reporter newInstance( String name ) 
    {				
        return new Dump() ;
    }

    public Object report( org.nlogo.api.Argument args[] , org.nlogo.api.Context context  )
    {
        return SoundExtension.dump();
    }
}
