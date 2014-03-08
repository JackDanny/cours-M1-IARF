===
===  NetLogo 4.1.3
===  April 3, 2011
===

WHAT'S NEW IN THIS VERSION?
See the "What's New?" section in the User Manual.

UPGRADING
Most models created in earlier versions of NetLogo will work in
NetLogo 4.1.3 with only minor updates to the code.  If
you have trouble, please consult
http://ccl.northwestern.edu/netlogo/docs/transition.html.

MAILING LISTS
We have three mailing lists for NetLogo:
- netlogo-announce: occasional release announcements only
- netlogo-users: discussions about NetLogo
- netlogo-educators: discussions about teaching with NetLogo
http://ccl.northwestern.edu/netlogo/ has info on all three.

CONTACT US!
The NetLogo home page is at:
  http://ccl.northwestern.edu/netlogo/
for contact information, or to report a bug, visit
  http://ccl.northwestern.edu/netlogo/contact.shtml

===

HOW TO RUN NETLOGO

- Windows users: Choose NetLogo from the Start menu.

- Mac users: Double click on the NetLogo icon in the NetLogo
  folder.  (You may wish to drag this icon to the dock for easy
  access.)

- Other platforms: You may be able to just double-click netlogo.sh in
  your file manager.  Or, from the command line, typical Unix shell
  commands would be:
  $ cd netlogo-4.1.3
  $ ./netlogo.sh
  You must have Java 5 or higher installed.

===

MANIFEST

The release package for this version of NetLogo includes:
* "NetLogo" application
* "NetLogo Logging" application (see Logging section of User Manual)
* "HubNet Client" application
* "NetLogo.jar", "NetLogoLite.jar", "HubNet.jar", "netlogo_logging.xml",
  "lib" internal support files and folder
* "Docs" folder containing a "NetLogo User Manual" -- complete
  documentation in HTML and printable PDF formats
* "Models" folder with several hundred NetLogo models and HubNet
  activities
* "Extensions" folder containing support for extra features.
* "Mathematica Link" folder containing support for the
  NetLogo-Mathematica link
* this "readme.txt" file

===

To reference this software in academic publications, please use:
Wilensky, U. (1999). NetLogo. http://ccl.northwestern.edu/netlogo.
Center for Connected Learning and Computer-Based Modeling,
Northwestern University, Evanston, IL.

The CCL gratefully acknowledges over a decade of support for our
NetLogo work. Much of that support came from the National Science
Foundation -- grant numbers REC-9814682 and REC-0126227, with further
support from REC-0003285, REC-0115699, DRL-0196044, CCF-ITR-0326542,
DRL-REC/ROLE-0440113, SBE-0624318, EEC-0648316, IIS-0713619,
DRL-RED-9552950, and DRL-REC-9632612. Additional support came from the
Spencer Foundation, Texas Instruments, and the Brady Fund.

===

NetLogo is Copyright 1999-2011 by Uri Wilensky. All rights reserved.

The NetLogo software, models and documentation are distributed free of
charge for use by the public to explore and construct
models. Permission to copy or modify the NetLogo software, models and
documentation for educational and research purposes only and without
fee is hereby granted, provided that this copyright notice and the
original author's name appears on all copies and supporting
documentation. For any other uses of this software, in original or
modified form, including but not limited to distribution in whole or
in part, specific prior permission must be obtained from Uri
Wilensky. The software, models and documentation shall not be used,
rewritten, or adapted as the basis of a commercial software or
hardware product without first obtaining appropriate licenses from Uri
Wilensky. We make no representations about the suitability of this
software for any purpose. It is provided "as is" without express or
implied warranty.

===

BehaviorSpace is Copyright 2009-2011 by Uri Wilensky. All rights reserved.

BehaviorSpace is free and open source software.  You can redistribute
it and/or modify it under the terms of the GNU Lesser General Public
License (LGPL) as published by the Free Software Foundation, either
version 3 of the License, or (at your option) any later version.

A copy of the LGPL is included in the NetLogo distribution.  See also
http://www.gnu.org/licenses/.

===

The extensions included with NetLogo are free and open source
software.  The exact copyright and licensing information varies from
extension to extension.  See the README file in each extension
directory.

===

Some parts of NetLogo are written in the Scala language and use the
Scala standard libraries.  The license for Scala is as follows:

Copyright (c) 2002-2008 EPFL, Lausanne, unless otherwise specified.
All rights reserved.

This software was developed by the Programming Methods Laboratory of the
Swiss Federal Institute of Technology (EPFL), Lausanne, Switzerland.

Permission to use, copy, modify, and distribute this software in source
or binary form for any purpose with or without fee is hereby granted,
provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

   3. Neither the name of the EPFL nor the names of its contributors
      may be used to endorse or promote products derived from this
      software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.

===

For random number generation, NetLogo uses the MersenneTwisterFast class
by Sean Luke.  The copyright for that code is as follows:

Copyright (c) 2003 by Sean Luke.
Portions copyright (c) 1993 by Michael Lecuyer
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
- Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
- Neither the name of the copyright owners, their employers, nor the
  names of its contributors may be used to endorse or promote products
  derived from this software without specific prior written
  permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

===

Parts of this software (specifically, the random-gamma primitive) are
based on code from the Colt library
(http://acs.lbl.gov/~hoschek/colt/).  The copyright for
that code is as follows:

Copyright 1999 CERN - European Organization for Nuclear Research.
Permission to use, copy, modify, distribute and sell this software and
its documentation for any purpose is hereby granted without fee,
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in
supporting documentation.  CERN makes no representations about the
suitability of this software for any purpose.  It is provided "as is"
without expressed or implied warranty.

===

This software uses the MRJ Adapter library, which is Copyright (c)
2003-2005 Steve Roy <sroy@roydesign.net>.  The library is covered by
the Artistic License.  MRJ Adapter is available from
https://mrjadapter.dev.java.net/ .

===

This software uses the Quaqua Look and Feel library, which is
Copyright (c) 2003-2005 Werner Randelshofer,
http://www.randelshofer.ch/, werner.randelshofer@bluewin.ch, All
Rights Reserved.  The library is covered by the GNU LGPL (Lesser
General Public License).  This license is available online from
http://www.gnu.org/copyleft/lesser.html and is also included with
every download of NetLogo (in the "docs" folder).

===

For the system dynamics modeler, NetLogo uses the JHotDraw library,
which is Copyright (c) 1996, 1997 by IFA Informatik and Erich Gamma. 
The library is covered by the GNU LGPL (Lesser General Public
License).  The text of that license is included in the "docs" folder
which accompanies the NetLogo download, and is also available from
http://www.gnu.org/copyleft/lesser.html .

===

For movie-making, NetLogo uses code adapted from
sim.util.media.MovieEncoder.java by Sean Luke, distributed under the
MASON Open Source License. The copyright for that code is as follows:

This software is Copyright 2003 by Sean Luke. Portions Copyright 2003
by Gabriel Catalin Balan, Liviu Panait, Sean Paus, and Dan Kuebrich.
All Rights Reserved

Developed in Conjunction with the George Mason University Center for
Social Complexity

By using the source code, binary code files, or related data included
in this distribution, you agree to the following terms of usage for
this software distribution. All but a few source code files in this
distribution fall under this license; the exceptions contain open
source licenses embedded in the source code files themselves. In this
license the Authors means the Copyright Holders listed above, and the
license itself is Copyright 2003 by Sean Luke.

The Authors hereby grant you a world-wide, royalty-free, non-exclusive
license, subject to third party intellectual property claims:

to use, reproduce, modify, display, perform, sublicense and distribute
all or any portion of the source code or binary form of this software
or related data with or without modifications, or as part of a larger
work; and under patents now or hereafter owned or controlled by the
Authors, to make, have made, use and sell ("Utilize") all or any
portion of the source code or binary form of this software or related
data, but solely to the extent that any such patent is reasonably
necessary to enable you to Utilize all or any portion of the source
code or binary form of this software or related data, and not to any
greater extent that may be necessary to Utilize further modifications
or combinations.

In return you agree to the following conditions:

If you redistribute all or any portion of the source code of this
software or related data, it must retain the above copyright notice
and this license and disclaimer. If you redistribute all or any
portion of this code in binary form, you must include the above
copyright notice and this license and disclaimer in the documentation
and/or other materials provided with the distribution, and must
indicate the use of this software in a prominent, publically
accessible location of the larger work. You must not use the Authors's
names to endorse or promote products derived from this software
without the specific prior written permission of the Authors.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS, NOR THEIR
EMPLOYERS, NOR GEORGE MASON UNIVERSITY, BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
THE USE OR OTHER DEALINGS IN THE SOFTWARE.

===

For movie-making, NetLogo uses code adapted from
JpegImagesToMovie.java by Sun Microsystems. The copyright for that
code is as follows:

Copyright (c) 1999-2001 Sun Microsystems, Inc. All Rights Reserved.

Sun grants you ("Licensee") a non-exclusive, royalty free, license to
use, modify and redistribute this software in source and binary code
form, provided that i) this copyright notice and license appear on all
copies of the software; and ii) Licensee does not utilize the software
in a manner which is disparaging to Sun.

This software is provided "AS IS," without a warranty of any kind. ALL
EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND WARRANTIES,
INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE OR NON-INFRINGEMENT, ARE HEREBY EXCLUDED. SUN AND
ITS LICENSORS SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE
AS A RESULT OF USING, MODIFYING OR DISTRIBUTING THE SOFTWARE OR ITS
DERIVATIVES. IN NO EVENT WILL SUN OR ITS LICENSORS BE LIABLE FOR ANY
LOST REVENUE, PROFIT OR DATA, OR FOR DIRECT, INDIRECT, SPECIAL,
CONSEQUENTIAL, INCIDENTAL OR PUNITIVE DAMAGES, HOWEVER CAUSED AND
REGARDLESS OF THE THEORY OF LIABILITY, ARISING OUT OF THE USE OF OR
INABILITY TO USE SOFTWARE, EVEN IF SUN HAS BEEN ADVISED OF THE
POSSIBILITY OF SUCH DAMAGES.

This software is not designed or intended for use in on-line control
of aircraft, air traffic, aircraft navigation or aircraft
communications; or in the design, construction, operation or
maintenance of any nuclear facility. Licensee represents and warrants
that it will not use or redistribute the Software for such purposes.

===

For 3D graphics rendering, NetLogo uses JOGL, a Java API for OpenGL.
For more information about JOGL, see http://jogl.dev.java.net/.
The library is distributed under the BSD license:

Copyright (c) 2003-2006 Sun Microsystems, Inc. All Rights Reserved.
 
Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions are
met:
   
- Redistribution of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
   
- Redistribution in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
   
Neither the name of Sun Microsystems, Inc. or the names of
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.
   
This software is provided "AS IS," without a warranty of any kind. ALL
EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND WARRANTIES,
INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE OR NON-INFRINGEMENT, ARE HEREBY EXCLUDED. SUN
MICROSYSTEMS, INC. ("SUN") AND ITS LICENSORS SHALL NOT BE LIABLE FOR
ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING, MODIFYING OR
DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES. IN NO EVENT WILL SUN OR
ITS LICENSORS BE LIABLE FOR ANY LOST REVENUE, PROFIT OR DATA, OR FOR
DIRECT, INDIRECT, SPECIAL, CONSEQUENTIAL, INCIDENTAL OR PUNITIVE
DAMAGES, HOWEVER CAUSED AND REGARDLESS OF THE THEORY OF LIABILITY,
ARISING OUT OF THE USE OF OR INABILITY TO USE THIS SOFTWARE, EVEN IF
SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
   
You acknowledge that this software is not designed or intended for use
in the design, construction, operation or maintenance of any nuclear
facility.

===

For 3D matrix operations, NetLogo uses the Matrix3D class.  It is
distributed under the following license:

Copyright (c) 1994-1996 Sun Microsystems, Inc. All Rights Reserved.

Sun grants you ("Licensee") a non-exclusive, royalty free, license to use,
modify and redistribute this software in source and binary code form,
provided that i) this copyright notice and license appear on all copies of
the software; and ii) Licensee does not utilize the software in a manner
which is disparaging to Sun.

This software is provided "AS IS," without a warranty of any kind. ALL
EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND WARRANTIES, INCLUDING ANY
IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
NON-INFRINGEMENT, ARE HEREBY EXCLUDED. SUN AND ITS LICENSORS SHALL NOT BE
LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING, MODIFYING
OR DISTRIBUTING THE SOFTWARE OR ITS DERIVATIVES. IN NO EVENT WILL SUN OR ITS
LICENSORS BE LIABLE FOR ANY LOST REVENUE, PROFIT OR DATA, OR FOR DIRECT,
INDIRECT, SPECIAL, CONSEQUENTIAL, INCIDENTAL OR PUNITIVE DAMAGES, HOWEVER
CAUSED AND REGARDLESS OF THE THEORY OF LIABILITY, ARISING OUT OF THE USE OF
OR INABILITY TO USE SOFTWARE, EVEN IF SUN HAS BEEN ADVISED OF THE
POSSIBILITY OF SUCH DAMAGES.

This software is not designed or intended for use in on-line control of
aircraft, air traffic, aircraft navigation or aircraft communications; or in
the design, construction, operation or maintenance of any nuclear
facility. Licensee represents and warrants that it will not use or
redistribute the Software for such purposes.

===

For Java bytecode generation, NetLogo uses the ASM library.  It is
distributed under the following license:

Copyright (c) 2000-2005 INRIA, France Telecom
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holders nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
THE POSSIBILITY OF SUCH DAMAGE.

===

For logging, NetLogo uses the Log4j library.  The copyright and license
for the library are as follows:

Copyright 1999-2005 The Apache Software Foundation

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

===

For dependency injection, NetLogo uses the PicoContainer library.  The
copyright and license for the library are as follows:

Copyright (c) 2003-2004, PicoContainer Organization
All rights reserved.

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice, this 
  list of conditions and the following disclaimer. 

  Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation 
  and/or other materials provided with the distribution. 

  Neither the name of the PicoContainer Organization nor the names of its 
  contributors may be used to endorse or promote products derived from this 
  software without specific prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
POSSIBILITY OF SUCH DAMAGE.

===

The GIS Extension uses several external libraries:

JScience - Java(TM) Tools and Libraries for the Advancement of Sciences.
Copyright (C) 2006 - JScience (http://jscience.org/)
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice
      and include this license agreemeent. 
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR 
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


JAVA Advanced Imaging API, Version 1.1.3

DISTRIBUTION BY DEVELOPERS.  Subject to the terms and conditions of
the Software License Agreement and the obligations, restrictions, and
exceptions set forth below, You may reproduce and distribute the
portions of Software identified below ("each a Redistributable"),
provided that you comply with the following (note that You may be
entitled to reproduce and distribute other portions of the Software
not defined here as a Redistributable under certain other licenses as
described in the THIRDPARTYLICENSEREADME):

(a) You distribute the Redistributable complete and unmodified and
only bundled as part of Your applets and applications ("Programs"), 

(b) You do not distribute additional software intended to replace any
component(s) of the Redistributable,

(c) You do not remove or alter any proprietary legends or notices
contained in or on the Redistributable.
 
(d) You only distribute the Redistributable subject to a license
agreement that protects Sun's interests consistent with the terms
contained in the Software License Agreement, and

(e) You agree to defend and indemnify Sun and its licensors from and
against any damages, costs, liabilities, settlement amounts and/or
expenses  (including attorneys' fees) incurred in connection with any
claim, lawsuit or action by any third party that arises or results
from the use or distribution of any and all Programs and/or
Redistributable.  


Apache Commons Codec

Copyright 2001-2008 The Apache Software Foundation

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


Apache Jakarta HttpClient

Copyright 1999-2007 Apache Software Foundation
		  
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


Apache Commons Logging

Copyright 2003-2007 Apache Software Foundation
		  
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


JTS Topology Suite Copyright (c) 2001 Vivid Solutions
The library is covered by the GNU LGPL (Lesser General Public
License).  The text of that license is included in the "docs" folder
which accompanies the NetLogo download, and is also available from
http://www.gnu.org/copyleft/lesser.html .
