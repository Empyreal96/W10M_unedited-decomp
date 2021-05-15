// AlpcpCaptureHandleAttributeInternal 
 
int __fastcall AlpcpCaptureHandleAttributeInternal(_DWORD *a1, int a2)
{
  _BYTE *v4; // r0
  _DWORD *v5; // r4
  int v6; // r5
  int v7; // r5
  int v8; // r2
  unsigned int *v10; // r2
  unsigned int v11; // r1
  int v12; // r1

  __mrc(15, 0, 13, 0, 3);
  if ( (*a1 & 0xFFF4FFFF) != 0 )
    return -1073741811;
  v4 = (_BYTE *)AlpcpAllocateBlob(AlpcHandleDataType, 32, 0);
  v5 = v4;
  if ( !v4 )
    return -1073741670;
  memset(v4, 0, 32);
  v6 = 8;
  if ( (*a1 & 0x10000) != 0 )
    v6 = 10;
  v7 = ObCaptureObjectStateForDuplication(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), a1[1], a1[3], v6);
  if ( v7 < 0 )
  {
    __dmb(0xBu);
    v10 = v5 - 3;
    do
    {
      v11 = __ldrex(v10);
      v12 = v11 - 1;
    }
    while ( __strex(v12, v10) );
    __dmb(0xBu);
    if ( v12 <= 0 )
    {
      if ( v12 )
        KeBugCheckEx(24, 0, (int)v5, 33, v12);
      AlpcpDestroyBlob(v5);
    }
  }
  else
  {
    v8 = *(_DWORD *)(ObTypeIndexTable[*(unsigned __int8 *)(v5[4] - 12) ^ (unsigned __int8)((unsigned __int16)(*((_WORD *)v5 + 8) - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie]
                   + 44);
    if ( (v8 & 0xFFD) == 0 )
      return sub_7F6A74();
    *v5 = *a1;
    v5[1] = v8;
    *(_DWORD *)(a2 + 24) = v5;
  }
  return v7;
}
