// CmpGetLastSetFileSize 
 
int __fastcall CmpGetLastSetFileSize(int a1, int a2)
{
  int v2; // r0
  int v3; // r2
  __int64 v4; // r0

  if ( a2 )
  {
    if ( a2 == 4 || a2 == 5 || a2 == 1 )
    {
      v2 = HvpLogTypeToLogArrayIndex(a2);
      v4 = *(_QWORD *)(v3 + 8 * (v2 + 244));
    }
    else
    {
      LODWORD(v4) = sub_7D2B50(a1, a2, a1);
    }
  }
  else
  {
    LODWORD(v4) = *(_DWORD *)(a1 + 1944);
  }
  return v4;
}
