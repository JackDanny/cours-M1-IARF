/** (c) 2004 Uri Wilensky. See README.txt for terms of use. **/

package edu.nwu.ccl.nlogo.extensions.sound ;

/**
 * NetLogo command stops all notes.
 **/
public class StopMusic
    implements org.nlogo.api.Command
{
    public String getAgentClassString()
    {
        return "OTP" ;
    }

    public org.nlogo.api.Syntax getSyntax()
    {
        return org.nlogo.api.Syntax.commandSyntax(  ) ;
    }

    public boolean getSwitchesBoolean() 
    { 
        return false; 
    }

    public org.nlogo.api.Command newInstance( String name ) 
    {				
        return new StopMusic();
    }

    public void perform( org.nlogo.api.Argument args[] , org.nlogo.api.Context context  )
        throws org.nlogo.api.ExtensionException , org.nlogo.api.LogoException
    {
        SoundExtension.stopNotes();
    }
}
