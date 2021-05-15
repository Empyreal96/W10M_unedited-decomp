// CmpAddToHiveFileList 
 
int __fastcall CmpAddToHiveFileList(int a1)
{
  int v2; // r5
  int v3; // r4
  unsigned int v5; // r1
  int v6; // [sp+14h] [bp-44h]
  unsigned int v7; // [sp+18h] [bp-40h]
  char v8[8]; // [sp+20h] [bp-38h] BYREF
  int v9; // [sp+28h] [bp-30h]
  int v10; // [sp+2Ch] [bp-2Ch]
  char *v11; // [sp+30h] [bp-28h]
  int v12; // [sp+34h] [bp-24h]
  int v13; // [sp+38h] [bp-20h]
  int v14; // [sp+3Ch] [bp-1Ch]

  if ( CmpHiveFileListHandle )
    goto LABEL_2;
  RtlInitUnicodeString((unsigned int)v8, L"\\registry\\machine\\system\\currentcontrolset\\control\\hivelist");
  v9 = 24;
  v10 = 0;
  v12 = 576;
  v11 = v8;
  v13 = 0;
  v14 = 0;
  v3 = ZwCreateKey();
  if ( v3 < 0 )
    return v3;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&CmpHiveFileListHandle);
  while ( !v5 && __strex(v7, (unsigned int *)&CmpHiveFileListHandle) );
  __dmb(0xBu);
  if ( !v5 )
  {
LABEL_2:
    v2 = ExAllocatePoolWithTag(1, 514, 1651592515);
    if ( !v2 )
      return -1073741801;
    if ( (*(_DWORD *)(a1 + 92) & 1) == 0 )
    {
      v3 = ZwQueryObject();
      if ( v3 < 0 )
      {
LABEL_7:
        ExFreePoolWithTag(v2);
        return v3;
      }
      *(_WORD *)(*(_DWORD *)(v2 + 4) + 2 * ((unsigned int)(v6 - 8) >> 1)) = 0;
    }
    v3 = ZwSetValueKey();
    goto LABEL_7;
  }
  return sub_7EA6DC();
}
