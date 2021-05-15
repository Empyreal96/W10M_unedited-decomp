// AslpFileGetExeWrapper 
 
int __fastcall AslpFileGetExeWrapper(int *a1, int a2)
{
  int v4; // r0
  int v5; // r4
  int v6; // r3
  int v7; // r0
  int v9; // [sp+10h] [bp-28h] BYREF
  int v10; // [sp+14h] [bp-24h]
  int v11[8]; // [sp+18h] [bp-20h] BYREF

  *a1 = 0;
  v9 = 0;
  v4 = AslpFileGetImageNtHeader(&v9, a2);
  v5 = v4;
  if ( v4 < 0 )
  {
    AslLogCallPrintf(1, (int)"AslpFileGetExeWrapper", 2445, "AslpFileGetImageNtHeader failed [%x]", v4);
    return v5;
  }
  if ( AslpFileHasSecuromWrapper(v9) )
  {
    v6 = 1;
    goto LABEL_15;
  }
  v7 = AslpFileHasActiveMarkWrapper(v11, v9, a2);
  v5 = v7;
  v10 = v7;
  if ( v7 >= 0 )
  {
    if ( v11[0] )
    {
      v6 = 2;
    }
    else if ( AslpFileHasArmadilloWrapper(v9) )
    {
      v6 = 3;
    }
    else
    {
      if ( !AslpHasStarForceWrapper(v9) )
      {
LABEL_16:
        v5 = 0;
        v10 = 0;
        return v5;
      }
      v6 = 4;
    }
LABEL_15:
    *a1 = v6;
    goto LABEL_16;
  }
  if ( v7 == -1073741275 )
    AslLogCallPrintf(
      2,
      (int)"AslpFileGetExeWrapper",
      2470,
      "AslpFileHasActiveMarkWrapper failed (FileSize: %I64u) [%x]",
      *(_QWORD *)(a2 + 528),
      -1073741275);
  else
    AslLogCallPrintf(1, (int)"AslpFileGetExeWrapper", 2472, "AslpFileHasActiveMarkWrapper failed [%x]", v7);
  return v5;
}
