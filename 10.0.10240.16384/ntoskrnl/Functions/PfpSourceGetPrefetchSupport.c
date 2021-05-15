// PfpSourceGetPrefetchSupport 
 
int __fastcall PfpSourceGetPrefetchSupport(_DWORD *a1, _DWORD *a2)
{
  int v4; // r4
  int v5; // r3
  int v6; // r2
  int v7; // r0
  int v8; // r5
  int v9; // r0
  int v10; // r3
  int v12; // [sp+10h] [bp-A0h] BYREF
  int v13; // [sp+14h] [bp-9Ch]
  int v14; // [sp+18h] [bp-98h] BYREF
  int v15; // [sp+20h] [bp-90h] BYREF
  int v16; // [sp+24h] [bp-8Ch]
  char *v17; // [sp+28h] [bp-88h]
  int v18; // [sp+2Ch] [bp-84h]
  int v19; // [sp+30h] [bp-80h]
  int v20; // [sp+34h] [bp-7Ch]
  int v21; // [sp+38h] [bp-78h]
  int v22; // [sp+3Ch] [bp-74h]
  char v23[8]; // [sp+40h] [bp-70h] BYREF
  unsigned __int16 v24[52]; // [sp+48h] [bp-68h] BYREF

  v4 = 0;
  *a2 = *a1;
  v5 = *a1;
  v6 = 0;
  v7 = 0;
  v13 = 0;
  v14 = 0;
  v12 = 0;
  if ( v5 )
  {
    if ( v5 == 1 )
    {
      RtlStringCbPrintfW(v24, 0x50u, (int)L"\\KernelObjects\\Session%d", a1[1]);
      RtlInitUnicodeString((unsigned int)v23, v24);
      v15 = 24;
      v16 = 0;
      v18 = 512;
      v17 = v23;
      v19 = 0;
      v20 = 0;
      v8 = NtOpenSession((unsigned int)&v12, 983043, (int)&v15, 0);
      if ( v8 < 0 )
      {
LABEL_18:
        v7 = v12;
        v6 = v13;
        goto LABEL_19;
      }
      v10 = v12;
      v6 = v13;
      v7 = 0;
      v12 = 0;
    }
    else
    {
      if ( v5 != 2 )
        return -1073741637;
      v15 = 24;
      v16 = 0;
      v18 = 512;
      v17 = 0;
      v19 = 0;
      v20 = 0;
      v22 = 0;
      v21 = a1[1];
      v8 = NtOpenProcess();
      if ( v8 < 0 )
        goto LABEL_18;
      v8 = ObReferenceObjectByHandleWithTag(v13, 0x1FFFFF, PsProcessType, 0, 1935107664, &v14, 0);
      v4 = v14;
      if ( v8 < 0 )
        goto LABEL_10;
      v9 = a1[3];
      if ( v9
        && v9 != ((*(_DWORD *)(v14 + 200) >> 3) & 0x1C000000 ^ (*(_DWORD *)(v14 + 204) ^ *(_DWORD *)(v14 + 200) ^ v14) & 0x1FFFFFFF) )
      {
        v8 = -1073741275;
LABEL_10:
        v7 = v12;
        v6 = v13;
        goto LABEL_16;
      }
      v7 = v12;
      v10 = v13;
      v6 = 0;
      v13 = 0;
    }
  }
  else
  {
    v10 = 0;
  }
  a2[1] = v10;
  v8 = 0;
LABEL_16:
  if ( v4 )
  {
    ObfDereferenceObjectWithTag(v4);
    goto LABEL_18;
  }
LABEL_19:
  if ( v6 )
  {
    NtClose();
    v7 = v12;
  }
  if ( v7 )
    NtClose();
  return v8;
}
