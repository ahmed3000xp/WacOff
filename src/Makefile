.PHONY: build

build:
	mkdir -p ../build
	aarch64-linux-gnu-gcc client.c -o ../build/client -Wall -Wextra -Werror -O2 -static
	aarch64-linux-gnu-gcc client_info.c -o ../build/client_info -Wall -Wextra -Werror -O2 -static
	gcc server.c -o ../build/server -Wall -Wextra -Werror -O2
