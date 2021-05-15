// EtwpCreateDirectoryFile 
 
int __fastcall EtwpCreateDirectoryFile(unsigned __int16 *a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v7; // r7
  int v9; // r4
  char v10[8]; // [sp+28h] [bp-38h] BYREF
  int v11; // [sp+30h] [bp-30h]
  int v12; // [sp+34h] [bp-2Ch]
  char *v13; // [sp+38h] [bp-28h]
  int v14; // [sp+3Ch] [bp-24h]
  int v15; // [sp+40h] [bp-20h]
  int v16; // [sp+44h] [bp-1Ch]

  v7 = 576;
  if ( !a5 )
    return sub_80AD60(a1, a1);
  RtlInitUnicodeString((unsigned int)v10, a1);
  if ( !a4 )
    v7 = 1600;
  v11 = 24;
  v12 = 0;
  v13 = v10;
  v14 = v7;
  v15 = 0;
  v16 = 0;
  v9 = ZwCreateFile();
  *a5 = 0;
  if ( a2 == 1 && v9 == -1073741757 )
    v9 = 0;
  return v9;
}
