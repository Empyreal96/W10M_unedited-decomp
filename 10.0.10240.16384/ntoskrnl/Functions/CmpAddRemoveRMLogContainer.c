// CmpAddRemoveRMLogContainer 
 
int __fastcall CmpAddRemoveRMLogContainer(_DWORD *a1)
{
  int v2; // r6
  __int16 *v3; // r9
  int v4; // r4
  int i; // r6
  int v6; // r0
  int v8; // [sp+10h] [bp-28h] BYREF
  int v9; // [sp+14h] [bp-24h]
  int v10; // [sp+18h] [bp-20h] BYREF
  int v11; // [sp+1Ch] [bp-1Ch]

  v8 = 0;
  v10 = 0;
  v11 = 0;
  v2 = 0;
  v9 = 0;
  if ( a1 == (_DWORD *)CmRmSystem )
  {
    v3 = &CmpLogPath;
    v4 = RtlStringFromGUIDEx(*((_DWORD *)off_60E8A4 + 8) + 112, (int)&v10, 1);
    if ( v4 < 0 )
      goto LABEL_13;
  }
  else
  {
    v4 = CmpQueryNameString(*(_DWORD *)(a1[12] + 1776), (unsigned __int16 *)&v8);
    if ( v4 < 0 )
    {
      v2 = v9;
      goto LABEL_16;
    }
    v3 = (__int16 *)&v8;
    v4 = RtlStringFromGUIDEx(*(_DWORD *)(a1[12] + 32) + 112, (int)&v10, 1);
    if ( v4 < 0 )
      goto LABEL_12;
  }
  for ( i = a1[9]; ; ++i )
  {
    v6 = CmpAddRemoveContainerToCLFSLog(a1[13], v3, &v10, &CmpLogExt, &CmpContainerSuffix, i, a1 + 10, 1, v8);
    v4 = v6;
    if ( v6 != -1073741771 && v6 != -1073741635 )
      break;
  }
  if ( v6 >= 0 )
    ++a1[9];
LABEL_12:
  v2 = v9;
LABEL_13:
  if ( v11 )
    RtlFreeAnsiString(&v10);
LABEL_16:
  if ( v2 )
    RtlFreeAnsiString(&v8);
  return v4;
}
