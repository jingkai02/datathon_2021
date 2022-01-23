
function expand(thistag)
{

   var tagobj = document.getElementById("item" + thistag);
   if(tagobj.style.display == 'none')
   {
      tagobj.style.display = '';
      document.getElementById(thistag).innerHTML = "-";
   }
   else 
   {
      tagobj.style.display = 'none';
      document.getElementById(thistag).innerHTML = "+";
   }
}

function expandAll(h, d, size)
{
   for(i = 0; i < size; i++)
   {
      var tagobj = document.getElementById("item" + i);
      document.getElementById(i).innerHTML = h;
      tagobj.style.display = d;
   }
}

function MM_openBrWindow(theURL, winName, features)
{
   //v2.0
   //Encode all parameters of given URL so department is encoded correctly.
   var url = encodeUrl(theURL);
   window.open(url, winName, features);
   //window.open(theURL, winName, features);
}

/* uncomment this to disallow right clicking on the pages
function oncontextmenuHandler() {  
    return false;  
}  
document.oncontextmenu = oncontextmenuHandler;  
*/

function encodeUrl(url)
{
    if (url.indexOf("?")>0)
    {
        encodedParams = "?";
        parts = url.split("?");
        params = parts[1].split("&");
        for(i = 0; i < params.length; i++)
        {
            if (i > 0)
            {
                encodedParams += "&";
            }
            if (params[i].indexOf("=")>0) //Avoid null values
            {
                p = params[i].split("=");
                if (p[0] == 'department')
                {
                	encodedParams += (p[0] + "=" + encodeURIComponent(p[1]));
                } else {
                	encodedParams += (p[0] + "=" + p[1]);
                }         
            }
            else
            {
                encodedParams += params[i];
            }
        }
        url = parts[0] + encodedParams;
    }
    return url;
}
