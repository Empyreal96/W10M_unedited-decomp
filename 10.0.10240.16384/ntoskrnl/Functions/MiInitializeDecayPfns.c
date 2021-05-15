// MiInitializeDecayPfns 
 
int MiInitializeDecayPfns()
{
  int v0; // r5
  _DWORD *v1; // r4
  int result; // r0

  dword_634698 = 0;
  dword_63469C = 0;
  v0 = 2048;
  v1 = (_DWORD *)(MmPfnDatabase + 24 * (dword_634690 + 2047));
  v1[5] = v1[5] & 0xFFF00000 | 1;
  do
  {
    result = RtlpInterlockedPushEntrySList((unsigned __int64 *)&dword_634698, v1);
    v1 -= 6;
    --v0;
  }
  while ( v0 );
  return result;
}
