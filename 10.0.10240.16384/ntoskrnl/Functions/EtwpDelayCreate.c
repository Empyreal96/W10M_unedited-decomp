// EtwpDelayCreate 
 
int __fastcall EtwpDelayCreate(int a1, int a2, _BYTE *a3, int a4, unsigned __int8 a5, char a6)
{
  int v7; // r0
  int v10; // r5
  unsigned int v11; // r6
  int v12; // r0
  unsigned int v14; // [sp+10h] [bp-30h] BYREF
  char v15[4]; // [sp+14h] [bp-2Ch] BYREF
  int v16; // [sp+18h] [bp-28h] BYREF
  int v17; // [sp+1Ch] [bp-24h]

  v7 = *(_DWORD *)(a2 + 4);
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v10 = EtwpCreateNtFileName(v7, &v14, v15);
  v11 = v14;
  if ( v10 >= 0 )
  {
    v12 = EtwpCreateDirectoryFile(v14, 0, a4, a5, a1, &v16, (unsigned __int8)*a3);
    v10 = v12;
    if ( a6 == 1 && v12 == -1073741766 )
      return sub_80ACE0();
  }
  if ( v11 )
    ExFreePoolWithTag(v11);
  if ( v10 >= 0 && *a3 == 1 && v17 == 2 )
    *a3 = 0;
  return v10;
}
