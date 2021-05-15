// FsRtlpOpenDev 
 
int __fastcall FsRtlpOpenDev(_DWORD *a1)
{
  int result; // r0
  char v3[8]; // [sp+20h] [bp-30h] BYREF
  int v4; // [sp+28h] [bp-28h]
  int v5; // [sp+30h] [bp-20h]
  int v6; // [sp+34h] [bp-1Ch]
  char *v7; // [sp+38h] [bp-18h]
  int v8; // [sp+3Ch] [bp-14h]
  int v9; // [sp+40h] [bp-10h]
  int v10; // [sp+44h] [bp-Ch]

  RtlInitUnicodeString((unsigned int)v3, L"\\Device\\Mup");
  v5 = 24;
  v6 = 0;
  v8 = 512;
  v7 = v3;
  v9 = 0;
  v10 = 0;
  result = ZwCreateFile();
  if ( result < 0 || (result = v4, v4 < 0) )
    *a1 = -1;
  return result;
}
