// KiCommitNodeAssignment 
 
int __fastcall KiCommitNodeAssignment(int result)
{
  int v1; // r7
  unsigned int v2; // r5
  __int16 v3; // r4
  int v4; // r2
  unsigned __int16 v5; // r1
  int v6; // r2
  int v7; // r3
  unsigned __int16 v8; // r1

  v1 = *(unsigned __int16 *)(result + 264);
  v2 = (unsigned __int16)KeNumberNodes;
  v3 = word_6376C4;
  v4 = 0;
  if ( KeNumberNodes )
  {
    v5 = 0;
    do
    {
      v6 = (int)*(&KeNodeBlock + v4);
      result = *(unsigned __int8 *)(v6 + 289);
      if ( (result & 2) != 0 && *(unsigned __int16 *)(v6 + 264) == v1 )
      {
        *(_BYTE *)(v6 + 289) = result | 4;
        *(_WORD *)(v6 + 264) = v3;
      }
      v4 = ++v5;
    }
    while ( v5 < v2 );
  }
  v7 = 0;
  if ( v2 )
  {
    v8 = 0;
    while ( (*((_BYTE *)*(&KeNodeBlock + v7) + 289) & 4) != 0 )
    {
      v7 = ++v8;
      if ( v8 >= v2 )
        goto LABEL_12;
    }
    result = sub_50A68C();
  }
  else
  {
LABEL_12:
    word_6376C4 = v3 + 1;
  }
  return result;
}
