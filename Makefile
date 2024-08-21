BACKEND_WORKDIR = backend
FRONTEND_WORKDIR = frontend

build: ${BACKEND_WORKDIR}/main.cpp
	emcc ${BACKEND_WORKDIR}/main.cpp -o ${FRONTEND_WORKDIR}/game.js -s USE_WEBGL2=1

run: build
	emrun ${FRONTEND_WORKDIR}/index.html --browser="/mnt/c/Program Files (x86)/Google/Chrome/Application/"chrome.exe