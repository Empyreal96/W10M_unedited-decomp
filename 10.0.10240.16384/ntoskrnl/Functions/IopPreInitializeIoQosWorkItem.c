// IopPreInitializeIoQosWorkItem 
 
_BYTE *__fastcall IopPreInitializeIoQosWorkItem(_BYTE *a1, unsigned int a2)
{
  unsigned __int64 v2; // r4
  _BYTE *result; // r0

  v2 = __PAIR64__((unsigned int)a1, a2);
  result = memset(a1, 0, 112);
  *(_DWORD *)HIDWORD(v2) = 0;
  *(_QWORD *)(HIDWORD(v2) + 8) = v2;
  *(_BYTE *)(HIDWORD(v2) + 80) = 1;
  *(_BYTE *)(HIDWORD(v2) + 82) = 4;
  *(_BYTE *)(HIDWORD(v2) + 81) = 0;
  *(_DWORD *)(HIDWORD(v2) + 84) = 0;
  *(_DWORD *)(HIDWORD(v2) + 88) = HIDWORD(v2) + 88;
  *(_DWORD *)(HIDWORD(v2) + 92) = HIDWORD(v2) + 88;
  return result;
}
