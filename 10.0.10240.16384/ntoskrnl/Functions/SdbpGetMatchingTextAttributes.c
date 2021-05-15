// SdbpGetMatchingTextAttributes 
 
int __fastcall SdbpGetMatchingTextAttributes(int a1, int a2, _DWORD *a3, unsigned int *a4, unsigned int *a5, int *a6, int *a7)
{
  int v7; // r6
  unsigned int v8; // r4
  int v9; // r10
  int v11; // r9
  int v12; // r0
  int v13; // r2
  int v14; // r3
  _WORD *v15; // r0
  _WORD *v16; // r8
  int v17; // r0
  int v18; // r2
  int v19; // r3
  int v20; // r7
  int v21; // r0
  unsigned int v22; // r6
  _BYTE *v23; // r0
  int v24; // r0
  int v25; // r7
  int v26; // r0

  v7 = a2;
  *a4 = 0;
  v8 = 0;
  v9 = 0x2000;
  *a5 = 0;
  *a3 = 0;
  *a6 = 0;
  *a7 = 0x2000;
  v11 = 0;
  v12 = SdbFindFirstTag(a1, a2, 24577);
  if ( !v12 )
  {
    AslLogCallPrintf(1, (int)"SdbpGetMatchingTextAttributes", 1302, "Failed to get MATCHING_TEXT file path", a2);
    return v11;
  }
  v15 = (_WORD *)SdbGetStringTagPtr(a1, v12, v13, v14);
  v16 = v15;
  if ( !v15 || !*v15 )
  {
    AslLogCallPrintf(1, (int)"SdbpGetMatchingTextAttributes", 1308, "Failed to read MATCHING_TEXT file path", a2);
LABEL_22:
    if ( v8 )
      ExFreePoolWithTag(v8);
    return v11;
  }
  v17 = SdbFindFirstTag(a1, v7, 36883);
  v20 = v17;
  if ( !v17 )
  {
    AslLogCallPrintf(1, (int)"SdbpGetMatchingTextAttributes", 1317, "Failed to read text to match", a2);
    return v11;
  }
  v21 = SdbGetTagDataSize(a1, v17, v18, v19);
  v22 = v21;
  if ( !v21 )
  {
    AslLogCallPrintf(1, (int)"SdbpGetMatchingTextAttributes", 1323, "Failed to get text to match blob", a2);
    return v11;
  }
  v23 = AslAlloc(v21, v21 + 2);
  v8 = (unsigned int)v23;
  if ( !v23 )
  {
    AslLogCallPrintf(1, (int)"SdbpGetMatchingTextAttributes", 1329, "Failed to allocate memory for text blob", a2);
    return v11;
  }
  if ( !SdbReadBinaryTag(a1, v20, (int)v23, v22) )
  {
    AslLogCallPrintf(1, (int)"SdbpGetMatchingTextAttributes", 1334, "Failed to read matching text blob", a2);
    goto LABEL_22;
  }
  v24 = SdbFindFirstTag(a1, a2, 16467);
  if ( !v24 )
  {
    AslLogCallPrintf(1, (int)"SdbpGetMatchingTextAttributes", 1343, "Failed to read text encoding", a2);
    goto LABEL_22;
  }
  v25 = SdbReadDWORDTag(a1, v24, 0);
  if ( !v25 )
  {
    AslLogCallPrintf(1, (int)"SdbpGetMatchingTextAttributes", 1349, "Failed to read encoding type", a2);
    goto LABEL_22;
  }
  v26 = SdbFindFirstTag(a1, a2, 16385);
  if ( v26 )
    v9 = SdbReadDWORDTag(a1, v26, 0x2000);
  v11 = 1;
  *a3 = v16;
  *a4 = v8;
  *a5 = v22;
  *a6 = v25;
  *a7 = v9;
  return v11;
}
