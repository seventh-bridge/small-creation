src = LWLibavVideoSource("D:\��Ƶ-����-ͼƬ\[BDMV][20190130][Sword Art Online Alicization][Vol.01]\BD\BDMV\STREAM\00002.m2ts", format="yuv420p8")
blur = RemoveGrain(src,20)
ave = mt_average(src,blur, u=3, v=3)
diff = mt_makediff(ave,blur,u=3,v=3)
diff