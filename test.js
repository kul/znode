    var znode = require('./build/Release/znode');

    znode = znode.Znode();
    process.stdin.resume();
    process.stdin.setEncoding('utf8');

    process.stdin.on('data', function (chunk) {
          process.stdout.write( znode.eval(chunk) );
    });
