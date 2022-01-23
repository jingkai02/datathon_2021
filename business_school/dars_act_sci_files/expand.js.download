function toggleDisplay(p,arrowDif,closeOthers) {
	if (arrowDif==null)  arrowDif = "";
	if (closeOthers==null)  closeOthers = false;
	var childDiv = p.parentNode.getElementsByTagName("DIV")[1];
	var arrowImg = p.getElementsByTagName("IMG")[0];
	if (childDiv.style.display=="none") {
		childDiv.style.display="";
		arrowImg.src = "./skins/arrow"+arrowDif+"_sq-open.gif";
		if (closeOthers) {
			var others = p.parentNode.parentNode.getElementsByTagName("SPAN");
			for (var i=0; i<others.length; i++) {
				if (others[i]!=p.parentNode) {
					var childDiv = others[i].getElementsByTagName("DIV")[1];
					var arrowImg = others[i].getElementsByTagName("DIV")[0].getElementsByTagName("IMG")[0];
					childDiv.style.display="none";
					arrowImg.src = "./skins/arrow"+arrowDif+"_sq.gif";
				}
			}
		}
	} else {
		childDiv.style.display="none";
		arrowImg.src = "./skins/arrow"+arrowDif+"_sq.gif";
	}
}

function openAll() {
	var others = document.getElementById("auditCell").getElementsByTagName("FONT");
	for (var i=0; i<others.length; i++) {
		var childDiv = others[i].getElementsByTagName("DIV")[1];
		if(childDiv) {
			var arrowImg = others[i].getElementsByTagName("DIV")[0].getElementsByTagName("IMG")[0];
			childDiv.style.display="";
			arrowImg.src = "./skins/arrow_sq-open.gif";
		}
	}
}

function closeAll() {
	var others = document.getElementById("auditCell").getElementsByTagName("FONT");
	for (var i=0; i<others.length; i++) {
		var childDiv = others[i].getElementsByTagName("DIV")[1];
		if(childDiv) {
			var arrowImg = others[i].getElementsByTagName("DIV")[0].getElementsByTagName("IMG")[0];
			childDiv.style.display="none";
			arrowImg.src = "./skins/arrow_sq.gif";
		}
	}
}