let http = require('http');
let fs = require('fs');
let url = require('url');
let path = require('path');

http.createServer(async (req, res) => {
  let documentRoot = '/home/yuwen/Documents/HistoryWork/web';
  let pathName = url.parse(req.url).pathname;
  let realPath = await path.join(documentRoot, pathName);

  fs.readFile(realPath, (err, data) => {
    if (err) {
      res.writeHead(404, {
        'content-type': `text/plain;charset='utf-8'`
      });
      res.write("404, can't find page!");
      res.end();
    } else {
      res.writeHead(200, {
        'content-type': `text/html;charset='utf-8'`
      });
      res.write(data);
      res.end();
    }
  });
}).listen(80);
