// PipCreateComputerId 
 
int __fastcall PipCreateComputerId(int a1, unsigned __int16 **a2, unsigned int a3, int a4)
{
  unsigned int v4; // r5
  unsigned int v5; // r6
  unsigned __int16 **v7; // r7
  _WORD *v8; // t1
  int v9; // r9
  int v10; // r0
  unsigned int v11; // r6
  _WORD *v12; // r4
  unsigned int v13; // r5
  int v14; // r4
  char v17[8]; // [sp+10h] [bp-78h] BYREF
  unsigned __int16 v18[56]; // [sp+18h] [bp-70h] BYREF

  LOWORD(v4) = 0;
  v5 = 0;
  v7 = a2;
  if ( !a3 )
    return -1073741811;
  do
  {
    if ( v5 )
      LOWORD(v4) = v4 + 2;
    v8 = *a2++;
    ++v5;
    v4 = (unsigned __int16)(*v8 + v4);
  }
  while ( v5 < a3 );
  if ( v4 <= 2 )
    return -1073741811;
  v9 = (unsigned __int16)(v4 + 2);
  v10 = ExAllocatePoolWithTag(1, v9, 1852403792);
  v11 = v10;
  if ( !v10 )
    return -1073741670;
  v12 = (_WORD *)v10;
  v13 = 0;
  do
  {
    if ( v13 )
      *v12++ = 38;
    if ( **v7 )
    {
      memmove((int)v12, *((_DWORD *)*v7 + 1), **v7);
      v12 += **v7 >> 1;
    }
    ++v13;
    ++v7;
  }
  while ( v13 < a3 );
  *v12 = 0;
  v14 = RtlGenerateClass5Guid((int)&PnpComputerIdNamespaceGuid, v11, v9 - 2, a4);
  if ( v14 >= 0 )
  {
    v14 = PnpStringFromGuid(a4, (int)v18);
    if ( v14 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v17, v18);
      v14 = ZwSetValueKey();
    }
  }
  ExFreePoolWithTag(v11);
  return v14;
}
