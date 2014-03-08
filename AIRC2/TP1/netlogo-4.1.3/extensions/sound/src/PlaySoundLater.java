/** (c) 2004 Uri Wilensky. See README.txt for terms of use. **/

package edu.nwu.ccl.nlogo.extensions.sound ;
import java.net.URL ;

/**
 * NetLogo command plays a sound file
 **/
public class PlaySoundLater
    implements org.nlogo.api.Command
{
    public String getAgentClassString()
    {
        return "OTP" ;
    }

    public org.nlogo.api.Syntax getSyntax()
    {
        int[] right = 
        { 
            org.nlogo.api.Syntax.TYPE_STRING, // sample URL
			org.nlogo.api.Syntax.TYPE_NUMBER, // delay
        };
        return org.nlogo.api.Syntax.commandSyntax( right ) ;
    }

    public boolean getSwitchesBoolean() 
    { 
        return false; 
    }

    public org.nlogo.api.Command newInstance( String name ) 
    {				
        return new PlaySoundLater() ;
    }


    public void perform( org.nlogo.api.Argument args[] , org.nlogo.api.Context context  )
        throws org.nlogo.api.ExtensionException , org.nlogo.api.LogoException
    {
		try {
			String soundpath = args[ 0 ].getString() ;
			int delay = Math.round( (float) args[ 1 ].getDoubleValue() * (float) 1000.0 );
			URL soundurl ;
			soundpath = context.attachCurrentDirectory( soundpath ) ;
			
			try {
				soundurl = new URL( context.attachCurrentDirectory( soundpath ) ) ;
			}
			catch( java.net.MalformedURLException ex )
			{
				soundurl = new URL("file", "", soundpath ) ;
			}
			SoundExtension.playSoundLater( soundurl, delay ) ;

		}
		catch( java.net.MalformedURLException ex )
		{
			throw new org.nlogo.api.ExtensionException
				( "Unable to open sound sample: " + ex.getMessage() ) ;
		}
    }
}
