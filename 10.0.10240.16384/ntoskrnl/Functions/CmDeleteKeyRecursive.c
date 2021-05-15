// CmDeleteKeyRecursive 
 
int __fastcall CmDeleteKeyRecursive(int a1, unsigned __int16 *a2, int a3, int a4)
{
  int v7; // r4
  unsigned int v8; // r0
  char *v9; // r7
  unsigned int v10; // r0
  int v12; // [sp+8h] [bp-40h]
  char v13[4]; // [sp+Ch] [bp-3Ch] BYREF
  char v14[8]; // [sp+10h] [bp-38h] BYREF
  int v15; // [sp+18h] [bp-30h]
  int v16; // [sp+1Ch] [bp-2Ch]
  char *v17; // [sp+20h] [bp-28h]
  int v18; // [sp+24h] [bp-24h]
  int v19; // [sp+28h] [bp-20h]
  int v20; // [sp+2Ch] [bp-1Ch]

  RtlInitUnicodeString((unsigned int)v14, a2);
  v18 = 576;
  v16 = a1;
  v17 = v14;
  v15 = 24;
  v19 = 0;
  v20 = 0;
  v7 = ZwOpenKey();
  if ( v7 >= 0 )
  {
    do
    {
      v7 = ZwEnumerateKey();
      if ( v7 < 0 )
        break;
      *(_WORD *)(a3 + 2 * (*(_DWORD *)(a3 + 12) >> 1) + 16) = 0;
      v8 = wcslen((unsigned __int16 *)(a3 + 16));
      v9 = (char *)ExAllocatePoolWithTag(1, 2 * (v8 + 1), 538987843);
      if ( !v9 )
      {
        v7 = -1073741670;
        break;
      }
      v10 = wcslen((unsigned __int16 *)(a3 + 16));
      wcscpy_s(v9, v10 + 1, (char *)(a3 + 16));
      v7 = CmDeleteKeyRecursive(v12, v9, a3, a4, 1, v13);
      ExFreePoolWithTag((unsigned int)v9);
    }
    while ( v7 >= 0 );
    if ( v7 == -2147483622 )
      v7 = 0;
    if ( v7 >= 0 )
      v7 = ZwDeleteKey();
    ZwClose();
  }
  return v7;
}
