// AdtpNormalizeAuditInfo 
 
int __fastcall AdtpNormalizeAuditInfo(int result)
{
  unsigned int v1; // r7
  int *v2; // r1
  int v3; // r2
  int v4; // r4

  if ( (*(_DWORD *)(result + 20) & 1) != 0 )
  {
    v1 = 0;
    v2 = (int *)(result + 24);
    if ( *(_DWORD *)(result + 8) )
    {
      while ( 1 )
      {
        v3 = *v2;
        if ( *v2 > 16 )
          break;
        if ( *v2 == 16 )
          return sub_81602C();
        if ( v3 > 0 && (v3 <= 2 || v3 == 4 || v3 > 7 && (v3 <= 9 || v3 == 13)) )
          goto LABEL_16;
LABEL_20:
        ++v1;
        v2 += 5;
        if ( v1 >= *(_DWORD *)(result + 8) )
          return result;
      }
      if ( v3 == 17 )
        JUMPOUT(0x816058);
      if ( v3 <= 22 || v3 > 25 && (v3 <= 27 || v3 != 34 && v3 > 32) )
        goto LABEL_20;
LABEL_16:
      v4 = v2[4] + result;
      v2[4] = v4;
      if ( v3 == 2 || v3 == 1 || v3 == 34 )
        *(_DWORD *)(v4 + 4) += result;
      goto LABEL_20;
    }
  }
  return result;
}
