## GitHub Copilot Chat

- Extension: 0.43.0 (prod)
- VS Code: 1.115.0 (41dd792b5e652393e7787322889ed5fdc58bd75b)
- OS: linux 5.15.148-tegra arm64
- GitHub Account: klclue03

## Network

User Settings:
```json
  "http.systemCertificatesNode": true,
  "github.copilot.advanced.debug.useElectronFetcher": true,
  "github.copilot.advanced.debug.useNodeFetcher": false,
  "github.copilot.advanced.debug.useNodeFetchFetcher": true
```

Connecting to https://api.github.com:
- DNS ipv4 Lookup: 140.82.113.6 (2 ms)
- DNS ipv6 Lookup: Error (19 ms): getaddrinfo ENOTFOUND api.github.com
- Proxy URL: None (4 ms)
- Electron fetch (configured): Error (40 ms): Error: net::ERR_CERT_DATE_INVALID
	at SimpleURLLoaderWrapper.<anonymous> (node:electron/js2c/utility_init:2:10684)
	at SimpleURLLoaderWrapper.emit (node:events:519:28)
  {"is_request_error":true,"network_process_crashed":false}
- Node.js https: Error (112 ms): Error: certificate is not yet valid
	at TLSSocket.onConnectSecure (node:_tls_wrap:1697:34)
	at TLSSocket.emit (node:events:519:28)
	at TLSSocket._finishInit (node:_tls_wrap:1095:8)
	at ssl.onhandshakedone (node:_tls_wrap:881:12)
- Node.js fetch: Error (155 ms): TypeError: fetch failed
	at node:internal/deps/undici/undici:14902:13
	at process.processTicksAndRejections (node:internal/process/task_queues:103:5)
	at async t._fetch (/home/nexusjetson/.vscode/extensions/github.copilot-chat-0.43.0/dist/extension.js:5293:5228)
	at async t.fetch (/home/nexusjetson/.vscode/extensions/github.copilot-chat-0.43.0/dist/extension.js:5293:4540)
	at async u (/home/nexusjetson/.vscode/extensions/github.copilot-chat-0.43.0/dist/extension.js:5325:186)
	at async Sg._executeContributedCommand (file:///usr/share/code/resources/app/out/vs/workbench/api/node/extensionHostProcess.js:501:48675)
  Error: certificate is not yet valid
  	at TLSSocket.onConnectSecure (node:_tls_wrap:1697:34)
  	at TLSSocket.emit (node:events:519:28)
  	at TLSSocket._finishInit (node:_tls_wrap:1095:8)
  	at ssl.onhandshakedone (node:_tls_wrap:881:12)

Connecting to https://api.githubcopilot.com/_ping:
- DNS ipv4 Lookup: 140.82.112.22 (2 ms)
- DNS ipv6 Lookup: Error (25 ms): getaddrinfo ENOTFOUND api.githubcopilot.com
- Proxy URL: None (55 ms)
- Electron fetch (configured): Error (44 ms): Error: net::ERR_CERT_DATE_INVALID
	at SimpleURLLoaderWrapper.<anonymous> (node:electron/js2c/utility_init:2:10684)
	at SimpleURLLoaderWrapper.emit (node:events:519:28)
  {"is_request_error":true,"network_process_crashed":false}
- Node.js https: Error (92 ms): Error: certificate is not yet valid
	at TLSSocket.onConnectSecure (node:_tls_wrap:1697:34)
	at TLSSocket.emit (node:events:519:28)
	at TLSSocket._finishInit (node:_tls_wrap:1095:8)
	at ssl.onhandshakedone (node:_tls_wrap:881:12)
- Node.js fetch: Error (106 ms): TypeError: fetch failed
	at node:internal/deps/undici/undici:14902:13
	at process.processTicksAndRejections (node:internal/process/task_queues:103:5)
	at async t._fetch (/home/nexusjetson/.vscode/extensions/github.copilot-chat-0.43.0/dist/extension.js:5293:5228)
	at async t.fetch (/home/nexusjetson/.vscode/extensions/github.copilot-chat-0.43.0/dist/extension.js:5293:4540)
	at async u (/home/nexusjetson/.vscode/extensions/github.copilot-chat-0.43.0/dist/extension.js:5325:186)
	at async Sg._executeContributedCommand (file:///usr/share/code/resources/app/out/vs/workbench/api/node/extensionHostProcess.js:501:48675)
  Error: certificate is not yet valid
  	at TLSSocket.onConnectSecure (node:_tls_wrap:1697:34)
  	at TLSSocket.emit (node:events:519:28)
  	at TLSSocket._finishInit (node:_tls_wrap:1095:8)
  	at ssl.onhandshakedone (node:_tls_wrap:881:12)

Connecting to https://copilot-proxy.githubusercontent.com/_ping:
- DNS ipv4 Lookup: 4.249.131.160 (6 ms)
- DNS ipv6 Lookup: Error (13 ms): getaddrinfo ENOTFOUND copilot-proxy.githubusercontent.com
- Proxy URL: None (36 ms)
- Electron fetch (configured): Error (238 ms): Error: net::ERR_CERT_DATE_INVALID
	at SimpleURLLoaderWrapper.<anonymous> (node:electron/js2c/utility_init:2:10684)
	at SimpleURLLoaderWrapper.emit (node:events:519:28)
  {"is_request_error":true,"network_process_crashed":false}
- Node.js https: Error (156 ms): Error: certificate is not yet valid
	at TLSSocket.onConnectSecure (node:_tls_wrap:1697:34)
	at TLSSocket.emit (node:events:519:28)
	at TLSSocket._finishInit (node:_tls_wrap:1095:8)
	at ssl.onhandshakedone (node:_tls_wrap:881:12)
- Node.js fetch: Error (169 ms): TypeError: fetch failed
	at node:internal/deps/undici/undici:14902:13
	at process.processTicksAndRejections (node:internal/process/task_queues:103:5)
	at async t._fetch (/home/nexusjetson/.vscode/extensions/github.copilot-chat-0.43.0/dist/extension.js:5293:5228)
	at async t.fetch (/home/nexusjetson/.vscode/extensions/github.copilot-chat-0.43.0/dist/extension.js:5293:4540)
	at async u (/home/nexusjetson/.vscode/extensions/github.copilot-chat-0.43.0/dist/extension.js:5325:186)
	at async Sg._executeContributedCommand (file:///usr/share/code/resources/app/out/vs/workbench/api/node/extensionHostProcess.js:501:48675)
  Error: certificate is not yet valid
  	at TLSSocket.onConnectSecure (node:_tls_wrap:1697:34)
  	at TLSSocket.emit (node:events:519:28)
  	at TLSSocket._finishInit (node:_tls_wrap:1095:8)
  	at ssl.onhandshakedone (node:_tls_wrap:881:12)

Connecting to https://mobile.events.data.microsoft.com: Error (309 ms): Error: net::ERR_CERT_DATE_INVALID
	at SimpleURLLoaderWrapper.<anonymous> (node:electron/js2c/utility_init:2:10684)
	at SimpleURLLoaderWrapper.emit (node:events:519:28)
  {"is_request_error":true,"network_process_crashed":false}
Connecting to https://dc.services.visualstudio.com: Error (193 ms): Error: net::ERR_CERT_DATE_INVALID
	at SimpleURLLoaderWrapper.<anonymous> (node:electron/js2c/utility_init:2:10684)
	at SimpleURLLoaderWrapper.emit (node:events:519:28)
  {"is_request_error":true,"network_process_crashed":false}
Connecting to https://copilot-telemetry.githubusercontent.com/_ping: Error (109 ms): Error: certificate is not yet valid
	at TLSSocket.onConnectSecure (node:_tls_wrap:1697:34)
	at TLSSocket.emit (node:events:519:28)
	at TLSSocket._finishInit (node:_tls_wrap:1095:8)
	at ssl.onhandshakedone (node:_tls_wrap:881:12)
Connecting to https://copilot-telemetry.githubusercontent.com/_ping: Error (91 ms): Error: certificate is not yet valid
	at TLSSocket.onConnectSecure (node:_tls_wrap:1697:34)
	at TLSSocket.emit (node:events:519:28)
	at TLSSocket._finishInit (node:_tls_wrap:1095:8)
	at ssl.onhandshakedone (node:_tls_wrap:881:12)
Connecting to https://default.exp-tas.com: Error (108 ms): Error: certificate is not yet valid
	at TLSSocket.onConnectSecure (node:_tls_wrap:1697:34)
	at TLSSocket.emit (node:events:519:28)
	at TLSSocket._finishInit (node:_tls_wrap:1095:8)
	at ssl.onhandshakedone (node:_tls_wrap:881:12)

Number of system certificates: 432

## Documentation

In corporate networks: [Troubleshooting firewall settings for GitHub Copilot](https://docs.github.com/en/copilot/troubleshooting-github-copilot/troubleshooting-firewall-settings-for-github-copilot).