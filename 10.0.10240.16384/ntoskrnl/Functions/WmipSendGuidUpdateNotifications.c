// WmipSendGuidUpdateNotifications 
 
_BYTE *__fastcall WmipSendGuidUpdateNotifications(int a1, int a2, _DWORD **a3)
{
  int v4; // r10
  int v5; // r8
  _BYTE *result; // r0
  unsigned int v7; // r7
  _DWORD *v8; // r3
  _DWORD *i; // r5
  _DWORD *v10; // t1
  int v11; // r1
  int v12; // r2
  int v13; // r3

  v4 = 16 * a2 + 8;
  v5 = a2;
  result = (_BYTE *)ExAllocatePoolWithTag(1, 16 * a2 + 110, 1885957463);
  v7 = (unsigned int)result;
  if ( result )
  {
    memset(result, 0, 48);
    *(_DWORD *)(v7 + 24) = -1265808991;
    *(_DWORD *)(v7 + 28) = 298903415;
    *(_DWORD *)(v7 + 32) = -1610609499;
    *(_DWORD *)(v7 + 36) = 271124169;
    *(_DWORD *)v7 = v4 + 102;
    *(_DWORD *)(v7 + 44) = 10;
    *(_DWORD *)(v7 + 48) = 64;
    *(_DWORD *)(v7 + 56) = 96;
    *(_DWORD *)(v7 + 60) = v4;
    *(_WORD *)(v7 + 64) = 28;
    RtlStringCbCopyW(v7 + 66, 0x1Cu);
    v8 = (_DWORD *)(*(_DWORD *)(v7 + 56) + v7);
    *v8 = a1;
    v8[1] = v5;
    for ( i = v8 + 2; v5; --v5 )
    {
      v10 = *a3;
      a3 += 2;
      v11 = v10[1];
      v12 = v10[2];
      v13 = v10[3];
      *i = *v10;
      i[1] = v11;
      i[2] = v12;
      i[3] = v13;
      i += 4;
    }
    WmipProcessEvent((unsigned int *)v7, 1, 0);
    result = (_BYTE *)ExFreePoolWithTag(v7);
  }
  return result;
}
