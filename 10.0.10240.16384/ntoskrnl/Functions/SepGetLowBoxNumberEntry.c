// SepGetLowBoxNumberEntry 
 
int __fastcall SepGetLowBoxNumberEntry(unsigned int *a1, int a2, int *a3, int a4)
{
  _DWORD *v4; // r10
  unsigned int v8; // r0
  int v9; // r3
  int v10; // r0
  int v11; // r4
  int result; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r1
  signed int v15; // r1
  int v16; // r5
  int v17; // r0
  _DWORD *v18; // r4
  int v19; // r5
  int v20; // r5
  int v21; // r0
  unsigned int v22; // r5
  int v23; // r9
  _DWORD v24[10]; // [sp+0h] [bp-28h] BYREF

  v24[0] = a2;
  v24[1] = a3;
  v24[2] = a4;
  v4 = (_DWORD *)a1[3];
  v8 = SepComputeSidSignature(a2);
  v10 = RtlLookupEntryHashTable(v4, v8, v24, v9);
  v11 = v10;
  if ( v10 )
  {
    if ( !RtlEqualSid((unsigned __int16 *)a2, *(unsigned __int16 **)(v10 + 16)) )
      return sub_7D6754();
  }
  else
  {
    v11 = 0;
  }
  if ( v11 )
  {
    v13 = (unsigned int *)(v11 + 12);
    do
    {
      v14 = __ldrex(v13);
      v15 = v14 + 1;
    }
    while ( __strex(v15, v13) );
    if ( v15 <= 1 )
      __fastfail(0xEu);
    *a3 = v11;
    result = 0;
  }
  else
  {
    v16 = (4 * *(unsigned __int8 *)(a2 + 1) + 39) & 0xFFFFFFFC;
    v17 = ExAllocatePoolWithTag(1, v16, 1934386515);
    v18 = (_DWORD *)v17;
    if ( v17 )
    {
      *(_DWORD *)(v17 + 16) = v17 + 28;
      RtlCopySid(v16 - 28, v17 + 28, a2);
      v19 = RtlFindClearBitsAndSet(a1 + 1, 1u, 0);
      if ( v19 == -1 )
      {
        v22 = 2 * RtlNumberOfSetBits(a1 + 1);
        if ( v22 > 0x10000 )
          goto LABEL_20;
        v23 = ExAllocatePoolWithTag(1, v22 >> 3, 1934386515);
        if ( !v23 )
          goto LABEL_20;
        ExFreePoolWithTag(a1[2]);
        a1[1] = v22;
        a1[2] = v23;
        RtlClearAllBits((int)(a1 + 1));
        RtlSetBits((_BYTE *)a1 + 4, 0, v22 >> 1);
        v19 = RtlFindClearBitsAndSet(a1 + 1, 1u, 0);
        if ( v19 == -1 )
          goto LABEL_20;
      }
      if ( v19 == 0xFFFF )
      {
LABEL_20:
        ExFreePoolWithTag((unsigned int)v18);
      }
      else
      {
        v18[6] = 0;
        v20 = v19 + 1;
        v18[3] = 1;
        v18[5] = v20;
        v21 = SepComputeSidSignature(a2);
        if ( RtlInsertEntryHashTable((int)v4, (int)v18, v21, 0) )
        {
          result = 0;
          *a3 = (int)v18;
          return result;
        }
        ExFreePoolWithTag((unsigned int)v18);
        RtlClearBits((_BYTE *)a1 + 4, 1u, v20 - 1);
      }
    }
    result = -1073741670;
  }
  return result;
}
