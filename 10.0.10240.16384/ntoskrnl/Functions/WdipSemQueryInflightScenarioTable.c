// WdipSemQueryInflightScenarioTable 
 
unsigned int __fastcall WdipSemQueryInflightScenarioTable(unsigned int a1, int a2, unsigned int *a3)
{
  unsigned int v3; // r5
  unsigned int *v4; // r6
  unsigned int v7; // r8
  int v8; // r4
  unsigned int v9; // r7
  unsigned int v10; // t1

  v3 = 0;
  v4 = a3;
  if ( a1 )
  {
    if ( a3 )
    {
      v7 = a3[125];
      v8 = 0;
      if ( v7 )
      {
        while ( 1 )
        {
          v10 = *v4++;
          v9 = v10;
          if ( !memcmp(a1, v10, 16) && a2 == *(unsigned __int16 *)(v9 + 16) )
            break;
          if ( ++v8 >= v7 )
            return v3;
        }
        v3 = v9;
      }
    }
  }
  return v3;
}
