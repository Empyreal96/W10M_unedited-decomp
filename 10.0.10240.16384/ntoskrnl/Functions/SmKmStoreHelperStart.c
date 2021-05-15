// SmKmStoreHelperStart 
 
int __fastcall SmKmStoreHelperStart(_DWORD *a1)
{
  int v2; // r4
  int v3; // r0
  int v5; // [sp+10h] [bp-18h] BYREF
  int v6[5]; // [sp+14h] [bp-14h] BYREF

  v2 = PsCreateSystemThread(&v5, 0x1FFFFF, 0, 0, 0, SmKmStoreHelperWorker, a1);
  if ( v2 >= 0 )
  {
    v2 = ObReferenceObjectByHandle(v5, 0x1FFFFF, 0, 0, v6, 0);
    v3 = v5;
    *a1 = v6[0];
    ObCloseHandle(v3, 0);
  }
  return v2;
}
