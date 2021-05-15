// PiDevCfgBuildDriverConfigurationId 
 
int __fastcall PiDevCfgBuildDriverConfigurationId(int a1, _DWORD *a2)
{
  int v3; // r2
  int v5; // r0
  int v6; // r0
  int v7; // r4
  int v8; // r3
  int v10; // [sp+8h] [bp-20h] BYREF
  int v11; // [sp+Ch] [bp-1Ch]
  __int16 v12[12]; // [sp+10h] [bp-18h] BYREF

  v3 = *(unsigned __int16 *)(a1 + 36);
  v10 = 0;
  v11 = 0;
  v5 = *(unsigned __int16 *)(a1 + 20) + v3 + 4;
  if ( *(_DWORD *)(a1 + 48) )
    v5 += *(unsigned __int16 *)(a1 + 44) + 2;
  if ( (unsigned int)(v5 + 2) > 0xFFFE )
  {
    v7 = -1073741562;
    goto LABEL_10;
  }
  LOWORD(v10) = v5;
  v6 = (unsigned __int16)(v5 + 2);
  HIWORD(v10) = v6;
  v11 = ExpAllocateStringRoutine(v6);
  if ( !v11 )
  {
    v7 = -1073741670;
    goto LABEL_10;
  }
  v7 = RtlUnicodeStringPrintfEx((unsigned __int16 *)&v10, (int)v12, 2048, L"%wZ:%wZ");
  if ( v7 >= 0 )
  {
    v8 = *(_DWORD *)(a1 + 48);
    if ( !v8 )
    {
LABEL_9:
      *a2 = v10;
      a2[1] = v11;
      v10 = 0;
      v11 = 0;
      goto LABEL_10;
    }
    v7 = RtlUnicodeStringPrintf(v12, (int)L",%wZ", a1 + 44, v8);
    if ( v7 >= 0 )
    {
      LOWORD(v10) = v12[0] + v10;
      goto LABEL_9;
    }
  }
LABEL_10:
  RtlFreeAnsiString(&v10);
  return v7;
}
