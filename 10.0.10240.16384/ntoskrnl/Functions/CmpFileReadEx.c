// CmpFileReadEx 
 
int __fastcall CmpFileReadEx(int a1, int a2, int *a3, int a4, unsigned int a5)
{
  int v5; // r6
  int v6; // r10
  unsigned int v7; // r9
  _DWORD *v8; // r5
  unsigned int v10; // r7
  unsigned int v11; // r8
  int v12; // r4
  int v13; // [sp+18h] [bp-40h] BYREF
  int v14; // [sp+1Ch] [bp-3Ch] BYREF
  int v15; // [sp+20h] [bp-38h]
  int *v16; // [sp+24h] [bp-34h]
  int v17[2]; // [sp+28h] [bp-30h] BYREF
  int v18; // [sp+30h] [bp-28h]
  int v19; // [sp+34h] [bp-24h]

  v5 = *(_DWORD *)(a1 + 4 * a2 + 1776);
  v15 = a4;
  v6 = *a3;
  v16 = a3;
  v13 = 0;
  v14 = 0;
  v7 = 0x10000000;
  if ( !v5 )
    return 0;
  v8 = *(_DWORD **)(a1 + 28);
  if ( CmpCreateEvent(1, &v14, &v13) < 0 )
    return sub_529D88();
  v10 = a5;
  if ( !a5 )
  {
LABEL_13:
    ObfDereferenceObjectWithTag(v13);
    ZwClose();
    *v16 = v6;
    return 0;
  }
  while ( 1 )
  {
    v18 = v6;
    v19 = 0;
    if ( v10 > v7 )
      v11 = v7;
    else
      v11 = v10;
    v12 = ZwReadFile();
    if ( v12 == 259 )
    {
      KeWaitForSingleObject(v13, 0, 0);
      v12 = v17[0];
    }
    if ( v12 < 0 && v7 > 0x10000 )
    {
      v7 >>= 1;
      goto LABEL_12;
    }
    v10 -= v11;
    v6 = v11 + v18;
    v15 += v11;
    if ( v12 < 0 )
      break;
    if ( v17[1] != v11 )
    {
      ObfDereferenceObjectWithTag(v13);
      ZwClose();
      if ( v8 )
      {
        v8[51] = 1;
        v8[52] = v5;
        v8[53] = v17;
      }
      v12 = -1073741807;
      CmRegistryIODebug = 1;
      dword_92094C = v5;
      dword_920950 = (int)v17;
      return v12;
    }
LABEL_12:
    if ( !v10 )
      goto LABEL_13;
  }
  if ( v8 )
  {
    v8[51] = 1;
    v8[52] = v5;
    v8[53] = v12;
  }
  CmRegistryIODebug = 1;
  dword_92094C = v5;
  dword_920950 = v12;
  ObfDereferenceObjectWithTag(v13);
  ZwClose();
  return v12;
}
