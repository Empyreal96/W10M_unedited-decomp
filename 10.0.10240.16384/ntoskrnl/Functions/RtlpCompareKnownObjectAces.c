// RtlpCompareKnownObjectAces 
 
BOOL __fastcall RtlpCompareKnownObjectAces(unsigned __int8 *a1, unsigned __int8 *a2)
{
  int v4; // r1
  int v5; // r3
  _DWORD *v6; // r5
  int v7; // r8
  int v8; // r10
  _DWORD *v9; // r0
  int v10; // r3
  _DWORD *v11; // r4
  _DWORD *v12; // r1
  int v14; // r1
  int v15; // r3
  int v16; // r0
  int v17; // r2

  v4 = *a2;
  if ( *((unsigned __int8 *)RtlBaseAceType + v4) != *((unsigned __int8 *)RtlBaseAceType + *a1)
    || *((_BYTE *)RtlIsSystemAceType + v4) && ((a2[1] ^ a1[1]) & 0xC0) != 0 )
  {
    return 0;
  }
  v5 = *((_DWORD *)a2 + 2);
  v6 = a2 + 12;
  v7 = v5 & 1;
  if ( (v5 & 1) == 0 )
    v6 = 0;
  v8 = v5 & 2;
  if ( (v5 & 2) != 0 )
  {
    if ( (v5 & 1) != 0 )
      v9 = a2 + 28;
    else
      v9 = a2 + 12;
  }
  else
  {
    v9 = 0;
  }
  v10 = *((_DWORD *)a1 + 2);
  v11 = a1 + 12;
  if ( (v10 & 1) == 0 )
    v11 = 0;
  if ( (v10 & 2) != 0 )
  {
    if ( (v10 & 1) != 0 )
      v12 = a1 + 28;
    else
      v12 = a1 + 12;
  }
  else
  {
    v12 = 0;
  }
  if ( v9 )
  {
    if ( !v12 || *v9 != *v12 || v9[1] != v12[1] || v9[2] != v12[2] || v9[3] != v12[3] )
      return 0;
  }
  else if ( v12 )
  {
    return 0;
  }
  if ( v6 )
  {
    if ( !v11 || *v6 != *v11 || v6[1] != v11[1] || v6[2] != v11[2] || v6[3] != v11[3] )
      return 0;
  }
  else if ( v11 )
  {
    return 0;
  }
  if ( (v10 & 1) != 0 )
    v14 = 16;
  else
    v14 = 0;
  if ( (v10 & 2) != 0 )
    v15 = 16;
  else
    v15 = 0;
  if ( v7 )
    v16 = 16;
  else
    v16 = 0;
  if ( v8 )
    v17 = 16;
  else
    v17 = 0;
  return RtlEqualSid((unsigned __int16 *)&a2[v17 + 12 + v16], (unsigned __int16 *)&a1[v15 + 12 + v14]);
}
