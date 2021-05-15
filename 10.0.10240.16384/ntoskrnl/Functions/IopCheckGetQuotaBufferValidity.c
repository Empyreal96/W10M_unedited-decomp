// IopCheckGetQuotaBufferValidity 
 
int __fastcall IopCheckGetQuotaBufferValidity(int a1, int a2, _DWORD *a3)
{
  int v5; // r6
  int i; // r4
  int v7; // r0
  int v8; // r3
  int v9; // r2
  int result; // r0

  v5 = a1;
  for ( i = a1; ; i += v8 )
  {
    if ( a2 < 20 || !RtlValidSid((_BYTE *)(i + 8)) )
      goto LABEL_9;
    v7 = RtlLengthSid(i + 8);
    v8 = *(_DWORD *)i;
    v9 = v7 + 8;
    if ( !*(_DWORD *)i )
      break;
    if ( v9 > v8 )
      goto LABEL_9;
    if ( (v8 & 3) != 0 )
      goto LABEL_9;
    a2 -= v8;
    if ( a2 < 0 )
      goto LABEL_9;
  }
  if ( a2 - v9 < 0 )
  {
LABEL_9:
    result = -1073741210;
    *a3 = i - v5;
    return result;
  }
  return 0;
}
