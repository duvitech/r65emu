#ifndef __RAM_H__
#define __RAM_H__

class ram: public Memory::Device {
public:
	virtual void operator= (byte c) { _mem[_acc] = c; }
	virtual operator byte () { return _mem[_acc]; }

	virtual void checkpoint(Stream &s) { s.write(_mem, sizeof(_mem)); }
	virtual void restore(Stream &s) { s.readBytes((char *)_mem, sizeof(_mem)); }

	ram (): Memory::Device(sizeof(_mem)) {}

private:
	byte _mem[1024];
};
#endif
