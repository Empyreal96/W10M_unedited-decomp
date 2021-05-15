// SmCrEncStart 
 
int __fastcall SmCrEncStart(int *a1, int a2, unsigned int a3)
{
  int result; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0
  _BYTE *v10; // r0
  _BYTE *v11; // r0
  int v12; // r1
  int v13; // [sp+10h] [bp-18h] BYREF

  result = BCryptOpenAlgorithmProvider((int)a1, (int)L"AES", 0, 1);
  if ( result >= 0 )
  {
    result = BCryptGetProperty(*a1, (int)L"BlockLength", (int)(a1 + 1));
    if ( result >= 0 )
    {
      v7 = a1[1];
      if ( !v7 || ((v7 - 1) & v7) != 0 )
      {
        result = -1073741453;
      }
      else
      {
        v8 = SmAlloc(a3, 1380150643);
        a1[2] = v8;
        if ( !v8 )
          return -1073741670;
        if ( a2 )
        {
          memmove(v8, a2, a3);
        }
        else
        {
          result = SmCrGenRandom(v8, a3);
          if ( result < 0 )
            return result;
        }
        v9 = a1[1];
        a1[3] = a3;
        v10 = (_BYTE *)SmAlloc(v9, 1380150643);
        a1[6] = (int)v10;
        if ( !v10 )
          return -1073741670;
        memset(v10, 0, a1[1]);
        result = BCryptGetProperty(*a1, (int)L"ObjectLength", (int)&v13);
        if ( result >= 0 )
        {
          v11 = (_BYTE *)SmAlloc(v13, 1380150643);
          a1[5] = (int)v11;
          if ( !v11 )
            return -1073741670;
          memset(v11, 0, v13);
          result = BCryptSetProperty(*a1, v12, (int)L"ChainingModeCCM");
          if ( result >= 0 )
          {
            result = BCryptGenerateSymmetricKey(*a1, (int)(a1 + 4), a1[5], v13, a1[2], a1[3]);
            if ( result >= 0 )
              result = 0;
          }
        }
      }
    }
  }
  return result;
}
