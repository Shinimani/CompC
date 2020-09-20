def countCandies(nodes,f_from,f_to,f_weights):
	n = len(f_weights)
	d={}
	for i in range(n):
		j = f_weights[i]
		if j in d.keys():
			k = len(d[j])
			flag = false
			for ii in range(k):
				if f_from[i] in d[j][ii] or f_to[i] in d[j][ii]:
					d[j][ii].add(f_from[i])
					d[j][ii].add(f_to[i])
					flag = true
					break
			if flag:
				d[j][k].add(f_from[i])
				d[j][k].add(f_to[i])		
		else:
			d[j]={}
			temp_dict = {}
			temp_dict.add(f_from[i])
			temp_dict.add(f_to[i])
			d[j][0]=temp_dict
	maxlen=0
	for dicti in d:
		for subdict in dicti:
			maxlen = max(maxlen,len(subdict))
	
