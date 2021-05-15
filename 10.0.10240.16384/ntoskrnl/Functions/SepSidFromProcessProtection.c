// SepSidFromProcessProtection 
 
int __fastcall SepSidFromProcessProtection(unsigned __int8 *a1)
{
  int v1; // r2
  int v2; // r3
  int *v4; // r3

  v1 = *a1;
  v2 = 0;
  switch ( v1 )
  {
    case 'a':
      v4 = &SeProcTrustLiteWinTcbSid;
      return *v4;
    case 'Q':
      v4 = &SeProcTrustLiteWinSid;
      return *v4;
    case 'R':
      v4 = &SeProcTrustWinSid;
      return *v4;
    case 'b':
      v4 = &SeProcTrustWinTcbSid;
      return *v4;
  }
  return v2;
}
