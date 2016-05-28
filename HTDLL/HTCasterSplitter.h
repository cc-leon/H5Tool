#pragma once

class HTCasterSplitter {
protected:
	UINT * _data;
	size_t _slots;
	UINT _base;
	UINT _multiplier;
	UINT _growth;

	UINT _getMinIndex();
	UINT _getTotal();
	VOID _begin();
public:
	explicit HTCasterSplitter(
		_In_ UINT CONST amount,
		_In_ UINT CONST slots,
		_In_ UINT CONST growth,
		_In_ UINT CONST base, 
		_In_ UINT CONST multiplier);
	UINT getOutput(_In_ UINT * CONST outputArray);
	
	~HTCasterSplitter();
};

