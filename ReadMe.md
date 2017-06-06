# Native Addon Skeleton (N-API)

This is a simple native addon skeleton for NodeJS - built on N-API.

The source code is originally based on one of the examples found in the official API documentation.

## Build

### Install build tools

Omitting the platform-specific tools required by the develpment platform.

```sh
$ sudo npm install -g node-gyp
```

### Build the addon

Install all project dependencies:

```sh
$ npm install
```

Configure and build:

```sh
$ node-gyp configure build
```

Test the addon:

```sh
$ npm test      # node test.js
```

## Resources 

* [N-API Documentation](https://nodejs.org/api/n-api.html)