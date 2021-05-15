// PiPnpRtlObjectEventCreate 
 
int __fastcall PiPnpRtlObjectEventCreate(int a1, int a2, int a3, int *a4)
{
  int v8; // r5
  int *v9; // r0
  int v10; // r3
  int v12; // r0
  _BYTE *v13; // r0
  _DWORD *v14; // r4
  int v15; // r3
  int v16; // r2
  int v17; // [sp+8h] [bp-A8h] BYREF
  _BYTE *v18; // [sp+Ch] [bp-A4h] BYREF
  _DWORD *v19; // [sp+10h] [bp-A0h] BYREF
  char *v20; // [sp+14h] [bp-9Ch] BYREF
  int v21; // [sp+18h] [bp-98h] BYREF
  char v22; // [sp+20h] [bp-90h] BYREF
  char *v23; // [sp+28h] [bp-88h]
  char v24[96]; // [sp+50h] [bp-60h] BYREF

  v20 = &v22;
  v17 = 0;
  *a4 = 0;
  v19 = 0;
  v8 = PiDmInitializeComparisonObject(a1, a2, v24);
  if ( v8 < 0 )
    goto LABEL_11;
  v23 = v24;
  v9 = (int *)RtlLookupElementGenericTableFullAvl(a3 + 12, (int)&v20, &v19, &v21);
  if ( v9 )
  {
    v10 = *v9;
    if ( *v9 )
    {
LABEL_4:
      *a4 = v10;
      return v8;
    }
  }
  v12 = PiDmGetObject(a2, a1, &v17);
  v8 = v12;
  if ( v12 != -1073741772 )
  {
    if ( v12 >= 0 )
    {
      v13 = (_BYTE *)ExAllocatePoolWithTag(1, 188, 1097887312);
      v14 = v13;
      v18 = v13;
      if ( !v13 )
        JUMPOUT(0x7C67FA);
      memset(v13, 0, 48);
      *v14 = 1;
      v15 = v17;
      v14[10] = 5;
      v16 = v21;
      v14[2] = v15;
      if ( !RtlInsertElementGenericTableFullAvl(a3 + 12, (int)&v18, 4u, 0, v19, v16) )
        JUMPOUT(0x7C6800);
      v10 = (int)v18;
      goto LABEL_4;
    }
LABEL_11:
    JUMPOUT(0x7C680A);
  }
  return sub_7C67F4();
}
