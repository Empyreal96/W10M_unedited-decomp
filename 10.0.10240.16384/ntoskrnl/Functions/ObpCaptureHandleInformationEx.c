// ObpCaptureHandleInformationEx 
 
int __fastcall ObpCaptureHandleInformationEx(int a1, int a2, _DWORD *a3, int a4, unsigned int a5, unsigned int *a6)
{
  unsigned int v8; // r4
  unsigned int v10; // r4
  int v11; // r2
  char v12; // r3

  v8 = *a6 + 28;
  *a6 = v8;
  if ( v8 < 0x1C )
    return -1073741675;
  if ( a5 < v8 )
    return -1073741820;
  v10 = *a3 & 0xFFFFFFF8;
  *(_DWORD *)(*(_DWORD *)a1 + 4) = a2;
  v11 = a3[1];
  v12 = *(_QWORD *)a3 & 6;
  if ( (v11 & 0x4000000) != 0 )
    v12 |= 8u;
  if ( (v11 & 0x2000000) != 0 )
    v12 |= 1u;
  *(_DWORD *)(*(_DWORD *)a1 + 20) = v12 & 7;
  *(_WORD *)(*(_DWORD *)a1 + 18) = *(unsigned __int8 *)(ObTypeIndexTable[*(unsigned __int8 *)(v10 + 12) ^ BYTE1(v10) ^ (unsigned __int8)ObHeaderCookie]
                                                      + 20);
  *(_DWORD *)(*(_DWORD *)a1 + 8) = a4;
  **(_DWORD **)a1 = v10 + 24;
  *(_WORD *)(*(_DWORD *)a1 + 16) = 0;
  *(_DWORD *)(*(_DWORD *)a1 + 12) = a3[1] & 0x1FFFFFF;
  *(_DWORD *)a1 += 28;
  return 0;
}
