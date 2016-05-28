#include <math.h>
#include "stdafxDLL.h"
#include "HTCasterSplitter.h"
HTCasterSplitter::HTCasterSplitter(
	_In_ UINT CONST amount,
	_In_ UINT CONST slots,
	_In_ UINT CONST growth,
	_In_ UINT CONST base,
	_In_ UINT CONST multiplier) :
	_data(NULL),
	_base(base),
	_multiplier(multiplier),
	_slots(slots),
	_growth(growth)
{
	_data = ALLOC(UINT, slots);
	::ZeroMemory(_data, slots*sizeof(UINT));
	_data[0] = amount;
	_begin();
}


HTCasterSplitter::~HTCasterSplitter() {
	if (_data != NULL) {
		FREE(_data);
	}
}

UINT HTCasterSplitter::_getMinIndex() {
	for (int i = _slots - 1; i >= 1; i--) {
		if (_data[i] < _data[i - 1]) {
			return i;
		}
	}
	return 0;
}

UINT HTCasterSplitter::_getTotal() {
	UINT result = 0;
	for (UINT i = 0; i < _slots;i++) {
		if (_data[i] > 0) {
			UINT currSpellPower = (UINT) (21.0 * ::log10(10.0 + 10.0 * _data[i] / _growth) - 22.0);
			if (currSpellPower < 1) {
				currSpellPower = 1;
			}
			result += currSpellPower*_multiplier + _base;
		}
	}
	return result;
}

VOID HTCasterSplitter::_begin() {
	do {
		UINT currDamage = _getTotal();
		UINT index = _getMinIndex();
		_data[0]--;
		_data[index]++;
		int cc = _getTotal();
		if (_getTotal() < currDamage) {
			_data[0]++;
			_data[index]--;
			return;
		}
	} while (_data[0] - _data[_getMinIndex()] >1);
}

UINT HTCasterSplitter::getOutput(_In_ UINT * CONST outputArray) {
	for (UINT i = 0; i < _slots;i++) {
		outputArray[i] = _data[i];
	}
	return _slots;
}