.PHONY: images
images:
	docker build --platform linux/amd64 -t yz271544/icecode:v1.0.0 -f Dockerfile .
