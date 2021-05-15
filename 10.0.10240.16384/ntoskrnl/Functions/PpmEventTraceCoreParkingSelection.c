// PpmEventTraceCoreParkingSelection 
 
int __fastcall PpmEventTraceCoreParkingSelection(int result, int a2, int a3, int a4)
{
  int v4; // r4
  int varg_r0; // [sp+C0h] [bp+8h]
  int varg_r1; // [sp+C4h] [bp+Ch]
  int varg_r2; // [sp+C8h] [bp+10h]
  int varg_r3; // [sp+CCh] [bp+14h]

  varg_r0 = result;
  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  if ( PpmEtwRegistered )
  {
    result = PpmEtwHandle;
    if ( PpmEtwHandle )
    {
      v4 = *(_DWORD *)(PpmEtwHandle + 16);
      if ( *(_DWORD *)(v4 + 56) && (*(unsigned __int8 *)(v4 + 60) >= 5u || !*(_BYTE *)(v4 + 60)) )
      {
        result = sub_540B74();
      }
      else if ( *(_BYTE *)(PpmEtwHandle + 52) )
      {
        JUMPOUT(0x540B98);
      }
    }
  }
  return result;
}
