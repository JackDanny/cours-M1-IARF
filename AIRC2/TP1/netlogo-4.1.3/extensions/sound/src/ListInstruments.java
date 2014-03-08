/** (c) 2004 Uri Wilensky. See README.txt for terms of use. **/

package edu.nwu.ccl.nlogo.extensions.sound;

/**
 * NetLogo command returns the names of all the available instruments.
 **/
public class ListInstruments
    implements org.nlogo.api.Reporter
{
    public String getAgentClassString()
    {
        return "OTP";
    }

    public org.nlogo.api.Syntax getSyntax()
    {
        return org.nlogo.api.Syntax.reporterSyntax( org.nlogo.api.Syntax.TYPE_LIST );
    }

    public boolean getSwitchesBoolean() 
    { 
        return false; 
    }

    public org.nlogo.api.Reporter newInstance( String name ) 
    {				
        return new ListInstruments();
    }

    public Object report( org.nlogo.api.Argument args[] , org.nlogo.api.Context context  )
        throws org.nlogo.api.ExtensionException , org.nlogo.api.LogoException
    {
        return new org.nlogo.api.LogoList( SoundExtension.INSTRUMENT_NAMES );
    }
}
