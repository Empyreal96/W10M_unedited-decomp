// DbgkCreateMinimalThread 
 
int __fastcall DbgkCreateMinimalThread(int result)
{
  int v1; // r4
  int v2[9]; // [sp+0h] [bp-B0h] BYREF
  int v3; // [sp+24h] [bp-8Ch]

  v1 = *(_DWORD *)(result + 116);
  if ( *(_DWORD *)(v1 + 340) )
  {
    v2[8] = 0;
    v3 = 0;
    v3 = *(_DWORD *)(result + 924);
    v2[0] = 2621456;
    v2[1] = 8;
    v2[6] = 1;
    result = DbgkpSendApiMessage(v1, 1, (int)v2);
  }
  return result;
}
