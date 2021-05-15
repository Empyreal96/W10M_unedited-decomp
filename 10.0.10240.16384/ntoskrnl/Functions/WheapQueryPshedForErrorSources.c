// WheapQueryPshedForErrorSources 
 
int __fastcall WheapQueryPshedForErrorSources(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  int result; // r0
  int v7; // [sp+0h] [bp-18h] BYREF
  int v8; // [sp+4h] [bp-14h] BYREF
  int v9[4]; // [sp+8h] [bp-10h] BYREF

  v9[1] = a4;
  v7 = 0;
  v8 = 0;
  v9[0] = 0;
  if ( PshedGetAllErrorSources(v9, &v7, &v8) != -1073741789 )
    JUMPOUT(0x966302);
  v7 = PshedAllocateMemory(v8);
  if ( !v7 )
    return sub_9662D8();
  if ( PshedGetAllErrorSources(v9, &v7, &v8) < 0 )
    JUMPOUT(0x9662EA);
  result = 0;
  *a2 = v7;
  *a1 = v9[0];
  return result;
}
