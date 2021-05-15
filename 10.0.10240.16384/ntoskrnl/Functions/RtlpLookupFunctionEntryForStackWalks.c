// RtlpLookupFunctionEntryForStackWalks 
 
int __fastcall RtlpLookupFunctionEntryForStackWalks(unsigned int a1, int *a2, int a3, int a4)
{
  int *v4; // r5
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int result; // r0
  unsigned int v12; // [sp+0h] [bp-20h]
  int *v13; // [sp+4h] [bp-1Ch]
  unsigned int _28; // [sp+28h] [bp+8h]

  _28 = a1;
  v12 = a1;
  v13 = a2;
  v4 = a2;
  v6 = a2[1];
  if ( a1 >= v6 && a1 < a2[2] + v6 )
    goto LABEL_8;
  if ( a1 <= MmHighestUserAddress )
  {
    v7 = RtlpLookupUserFunctionTable(a1, a2);
    goto LABEL_10;
  }
  if ( a1 >= dword_616494 && a1 < dword_616498 + dword_616494 )
  {
    v8 = dword_616494;
    v9 = dword_616498;
    v10 = *(_DWORD *)algn_61649C;
    *v4 = dword_616490;
    v4[1] = v8;
    v4[2] = v9;
    v4[3] = v10;
LABEL_8:
    v7 = *v4;
    goto LABEL_10;
  }
  v7 = RtlpxLookupFunctionTable(a1, a2);
LABEL_10:
  if ( v7 )
    return RtlpSearchFunctionTable(v7, (unsigned int)v4[3] >> 3, a1, v4[1], v12, v13, a3, a4);
  result = 0;
  v4[1] = 0;
  v4[2] = 0;
  return result;
}
