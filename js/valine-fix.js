for (const comment of document.getElementsByClassName("vcontent"))
  for (const codeblock of comment.getElementsByTagName("pre"))
    for (const colorspan of codeblock.getElementsByTagName("span")) {
      colorspan.className = colorspan.style.color.replaceAll("#", "hx-")
                                                 .replaceAll(", ", "-")
                                                 .replaceAll("(", "-")
                                                 .replaceAll(")", "");
      colorspan.style.color = "";
    }